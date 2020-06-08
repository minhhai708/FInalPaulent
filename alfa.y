%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "alfa.tab.h"
#include "generacion.h"
#include "tablaSimbolos.h"

extern int yylex();
extern char* yytext;
extern int row;
extern int column;
extern void yyerror();
extern int aux;
extern FILE * file;
FILE * pfasm;
FILE * yyin;
/*int vector_actual_tamano;
int pos_variable_local_actual;
int num_parametros_actual;
int num_variables_actual;
int num_variables_locales_actual;
int pos_parametro_actual;
int tipo_funcion;
*/
static int clase_actual, ambito_actual, tipo_actual;
static int num_variables_locales_actual = 0;
static int pos_variable_local_actual = 1;
static int tamanio_vector_actual = 0;
static int pos_parametro_actual = -1;
static int num_parametros_actual = 0;
static int fn_return = 0;

void ASSERT_SEMANTICO(int cond, char* err_msg, char* extra_info) {
    if (!(cond)) {
        yyerror(err_msg);
        printf("__________ERROR:%s '%s'\n",err_msg, extra_info);
        exit(0);
    }
}
/*

static int en_explist = 0;
static int etiqueta = 1;
*/
%}
%union {
    tipo_atributos atributos;
}
/*Terminales*/
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MASIGUAL
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR
%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA
%token <numero> TOK_TRUE
%token <numero> TOK_FALSE
%token <numero> TOK_ERROR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%left TOK_AND TOK_OR
%left TOK_IGUAL TOK_NOT
%left TOK_PARENTESISIZQUIERDO TOK_PARENTESISDERECHO
%left TOK_CORCHETEIZQUIERDO TOK_CORCHETEDERECHO
/*numero,cola_identificador,alfanumerico,letra,digito*/
%type <atributos> exp
%type <atributos> identificador identificador_nuevo
%type <atributos> idpf fn_name fn_declaration funcion
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica

/*
%type <atributos> condicional
%type <atributos> identificador_nuevo identificador_uso
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> idf_llamada_funcion
%type <atributos> lista_expresiones resto_lista_expresiones
%type <atributos> if_exp if_exp_sentencias
%type <atributos> while_exp while
%type <atributos> compare_with compare_less compare_equal compare_greater
%type <atributos> inicializacion_vector lista_inicializaciones
*/
%start programa
%%
programa        : TOK_MAIN TOK_LLAVEIZQUIERDA _inicio declaraciones  _escritura1 funciones _escritura2 sentencias _final TOK_LLAVEDERECHA
                    { fprintf (file,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n"); }
                ;
_inicio         : { // Inicializacion inicial
                  iniciar_scope();
                  escribir_subseccion_data(pfasm);
                  escribir_cabecera_bss(pfasm);
                  }
                ;
      /*FINISHED*/
_escritura1     : { // Declaramos en el segmento bss todas las variables globales declaradas
                  INFO_SIMBOLO* simbolos = simbolos_globales();
                  for (; NULL != simbolos; simbolos = simbolos->next) {
                    if (VARIABLE == simbolos->categoria)
                      declarar_variable(pfasm, simbolos->lexema, simbolos->tipo, (VECTOR == simbolos->clase) ? simbolos->adicional1 : 1);
                    }
                  escribir_segmento_codigo(pfasm);}
                ;
_escritura2     : { escribir_inicio_main(pfasm);}
                ;
_final          : { escribir_fin(pfasm); liberar_scope(); }
                ;
declaraciones   : declaracion { fprintf (file,";R2:\t<declaraciones> ::= <declaracion>\n"); }
		            | declaracion declaraciones{ fprintf (file,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n"); }
		            ;

declaracion     : clase identificadores TOK_PUNTOYCOMA {fprintf(file,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n"); }
                ;
clase           : clase_escalar { fprintf (file,";R5:\t<clase> ::= <clase_escalar>\n"); clase_actual = ESCALAR;		        }
		            |clase_vector {fprintf (file,";R7:\t<clase> ::= <clase_vector>\n"); clase_actual = VECTOR;  }
		            ;
clase_escalar   : tipo { fprintf (file,";R9:\t<clase_escalar> ::= <tipo>\n");		}
                ;
tipo            : TOK_INT {		fprintf(file,";R10:\t<tipo> ::= int\n"); tipo_actual = ENTERO;}
		            | TOK_BOOLEAN {fprintf(file,";R11:\t<tipo> ::= boolean\n"); tipo_actual = BOOLEANO;   }
		            ;
clase_vector    : TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
		              fprintf(file,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                  tamanio_vector_actual = $4.valor_entero;
                  ASSERT_SEMANTICO(tamanio_vector_actual >= 1, "El tamanyo del vector excede los limites permitidos ", NULL);
                  ASSERT_SEMANTICO(tamanio_vector_actual <= MAX_TAMANIO_VECTOR, "El tamanyo del vector excede los limites permitidos", NULL);}
                ;
identificadores : identificador_nuevo { fprintf(file,";R18:\t<identificadores> ::= <identificador>\n"); }
			          | identificador_nuevo TOK_COMA identificadores{ fprintf(file,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
                ;
funciones       : funcion funciones{fprintf(file,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
          			|/* empty regla 21 */ {fprintf(file,";R21:\t<funciones> ::=\n");}
                ;
funcion : fn_declaration sentencias TOK_LLAVEDERECHA{			fprintf(file,";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
    	ambito_actual = 0;
    	cerrar_scope_local();
    	ASSERT_SEMANTICO(fn_return != 0, "Funcion sin sentencia de retorno", $1.lexema);
			};
fn_declaration  : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
	    INFO_SIMBOLO* info = get_SimbolByID_SoloGlobal($1.lexema);
	    info->adicional1 = num_parametros_actual;
	    info->adicional2 = num_variables_locales_actual;
	    info = get_SimbolByID($1.lexema);
	    info->adicional1 = num_parametros_actual;
	    info->adicional2 = num_variables_locales_actual;
	    $$ = $1;
	    declararFuncion(pfasm, $$.lexema, num_variables_locales_actual);
      };
fn_name : TOK_FUNCTION tipo identificador {
      INFO_SIMBOLO* info = get_SimbolByID_SoloGlobal($3.lexema);
      ASSERT_SEMANTICO(NULL == info, "Declaracion duplicada", NULL);
      /* Abrimos un nuevo ambito */
      /* Esta funcion declarara el nuevo ambito y realizara las inserciones correspondientes */
      /* Aun no sabemos numero de variable y parametros se modificara a posteriori */
      declarar_funcion($3.lexema, tipo_actual, -1, -1);
      /* Inicializamos variables de la funcion */
      num_variables_locales_actual = 0;
  		pos_variable_local_actual = 1;
  		num_parametros_actual = 0;
  		pos_parametro_actual = 0;
  		fn_return = 0;
      tamanio_vector_actual = 0;
	    /* Propagamos el nombre de la funcion */
  		$$ = $3;
  		ambito_actual = 1;
      };
parametros_funcion  : parametro_funcion resto_parametros_funcion{fprintf(file,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n"); }
	              |/* empty  regla 24*/{ fprintf(file,";R24:\t<parametros_funcion> ::=\n");}
	              ;
resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(file,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
          			|/* empty  regla 26*/ {fprintf(file,";R26:\t<resto_parametros_funcion> ::=\n"); }
          			;
idpf            : identificador {
                $$ = $1;
                clase_actual = ESCALAR;
                }
                ;
parametro_funcion : tipo idpf {	fprintf (file,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
          			INFO_SIMBOLO* info = uso_solo_local($2.lexema);
                ASSERT_SEMANTICO(NULL == info, "Declaracion duplicada", NULL);
                /* Declaramos el parametro en la tabla local */
                /* Adicional 2 indica la posicion del parametro en llamada a funcion */
                declarar_local($2.lexema, PARAMETRO, tipo_actual, clase_actual, 0, pos_parametro_actual);
                /* Se debe incrementar tras insertar en la tabla para que el primer parametro comience en 0 */
                pos_parametro_actual++;
                num_parametros_actual++;
          			};
declaraciones_funcion: declaraciones { fprintf (file,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n"); }
			          | /* empty regla 29 */ { fprintf (file,";R29:\t<declaraciones_funcion> ::=\n");};
sentencias      : sentencia { 	fprintf (file,";R30:\t<sentencias> ::= <sentencia>\n"); }
		            |sentencia sentencias{ fprintf (file,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n"); };
sentencia       : sentencia_simple TOK_PUNTOYCOMA { fprintf (file,";R32:\t<sentencia> ::= <sentencia_simple> ;\n"); }
			          |bloque{ fprintf (file,";R33:\t<sentencia> ::= <bloque>\n"); };
sentencia_simple: asignacion { fprintf(file,";R34:\t<sentencia_simple> ::= <asignacion>\n"); }
          			|lectura{ fprintf(file,";R35:\t<sentencia_simple> ::= <lectura>\n"); }
          			|escritura  { fprintf(file,";R36:\t<sentencia_simple> ::= <escritura>\n"); }
          			|retorno_funcion { fprintf(file,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
                };

bloque          : condicional {fprintf(file,";R40:\t<bloque> ::= <condicional>\n");}
          			|bucle {fprintf(file,";R41:\t<bloque> ::= <bucle>\n");}
                ;
asignacion      : identificador TOK_ASIGNACION exp { fprintf(file,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
          INFO_SIMBOLO* info = get_SimbolByID($1.lexema);
          ASSERT_SEMANTICO(NULL != info, "Asignacion incompatible", NULL);
          ASSERT_SEMANTICO(FUNCION != info->categoria, "Asignacion incompatible", NULL);
          ASSERT_SEMANTICO(VECTOR != info->clase, "Asignacion incompatible", NULL);
          ASSERT_SEMANTICO($3.tipo == info->tipo, "Asignacion incompatible", NULL);
          /* Caso variables globales */
          if(NULL == uso_solo_local($1.lexema)) {
            asignar(pfasm, $1.lexema, $3.es_direccion);
          /* Caso parametros en funciones en funciones */
          } else if (PARAMETRO == info->categoria){
            escribirParametro(pfasm, info->adicional2, num_parametros_actual);
                              /* El ultimo caso son variables locales */
          } else {
            escribirVariableLocal(pfasm, $3.es_direccion, info->adicional2);
          }
        }
      | elemento_vector TOK_ASIGNACION exp {fprintf(file,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
        asignar_vector(pfasm, $3.es_direccion);}
      ;
elemento_vector: 	identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {fprintf(file,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
        INFO_SIMBOLO * info = get_SimbolByID_SoloGlobal($1.lexema);
        ASSERT_SEMANTICO(info != NULL,"Identificador de vector declarado", $1.lexema);
        ASSERT_SEMANTICO(VECTOR == info->clase, "Intento de indexacion de una variable que no es de tipo vector", NULL);
        ASSERT_SEMANTICO(ENTERO == $3.tipo, "El indice en una operacion de indexacion tiene que ser de tipo entero", NULL);
        escribir_elemento_vector(pfasm, info->adicional1, $1.lexema, $3.es_direccion);
        $$.tipo = info->tipo;
        $$.es_direccion = 0;
			};
      /*FINISHED*/
condicional : if_exp_sentencias{
            fprintf(file,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
            generar_endif(pfasm, $1.etiqueta);}
            | if_exp_sentencias TOK_ELSE '{' sentencias '}'  {
            fprintf(file,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
            generar_endif(pfasm, $1.etiqueta);}
            };
if_exp_sentencias : if_exp sentencias TOK_LLAVEDERECHA{
            $$.etiqueta = $1.etiqueta;
            generar_else(pfasm, $$.etiqueta);
            };
if_exp      :	TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA  {
            ASSERT_SEMANTICO(BOOLEANO == $3.tipo, "Condicional con condicion de tipo int", NULL);
            $$.etiqueta = etiqueta++;
            generar_if_then(pfasm, $3.es_direccion, $$.etiqueta);
            };
compare_with : TOK_COMPARE exp TOK_WITH exp '{' TOK_LESS {
      $$.etiqueta = etiqueta++;
      ASSERT_SEMANTICO($2.tipo == ENTERO, "se esperaba una expresion de tipo entero", NULL);
      ASSERT_SEMANTICO($4.tipo == ENTERO, "se esperaba una expresion de tipo entero", NULL);
      generar_compare_with(pfasm, $2.es_direccion, $4.es_direccion, $$.etiqueta);
      generar_salto_less(pfasm, $$.etiqueta);
      };

compare_less : compare_with sentencias TOK_EQUAL {
      $$.etiqueta = $1.etiqueta;
      generar_salto_equal(pfasm, $$.etiqueta);
      };
compare_equal : compare_less sentencias TOK_GREATER {
      $$.etiqueta = $1.etiqueta;
      generar_salto_greater(pfasm, $$.etiqueta);
      };

compare_greater : compare_equal sentencias '}' {
      $$.etiqueta = $1.etiqueta;
      };

bucle           : TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
			fprintf(file,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
			    };
lectura         : TOK_SCANF identificador{
                fprintf(file,";R54:\t<lectura> ::= scanf <identificador>\n");
              /*  INFO_SIMBOLO* info = get_SimbolByID($2.lexema);

                ASSERT_SEMANTICO(NULL != info, "Acceso a variable no declarada", $2.lexema);
                ASSERT_SEMANTICO(FUNCION != info->categoria, "Solo podemos leer enteros o booleanos", NULL);
                ASSERT_SEMANTICO(ESCALAR == info->clase, "Solo podemos leer escalares", NULL);
*/
                /* Llamamos a scanf, restauramos la pila en funcion del tipo
                if(NULL == uso_solo_local($2.lexema)){
                leer(pfasm, info->lexema, info->tipo);
                } else if(PARAMETRO == info->categoria) {
                escribirParametro(pfasm, 1, info->adicional2, num_parametros_actual);
                leer_ya_apilado(pfasm, info->tipo);
                } else {
                escribirVariableLocal(pfasm, 1, info->adicional2);
                leer_ya_apilado(pfasm, info->tipo);
                }
*/
                };
escritura       : TOK_PRINTF exp{fprintf(file,";R56:\t<escritura> ::= printf <exp>\n");
                escribir(pfasm, $2.es_direccion, $2.tipo);}
                ;
retorno_funcion : TOK_RETURN exp{fprintf(file,";R61:\t<retorno_funcion> ::= return <exp>\n");
                ASSERT_SEMANTICO(ambito_actual, "Sentencia de retorno fuera del cuerpo de una funcion", NULL);
                retornarFuncion(pfasm, $2.es_direccion);
                fn_return++;}
                ;
exp   : exp TOK_MAS exp {
        fprintf(file,";R72:\t<exp> ::= <exp> + <exp>\n");
        sumar(pfasm, $1.es_direccion, $3.es_direccion);
        /* Propaga correctamente los atributos */
        $$.tipo = ENTERO;
        $$.es_direccion = 0;}
			|exp TOK_MENOS exp{fprintf(file,";R73:\t<exp> ::= <exp> - <exp>\n");			}
			|exp TOK_DIVISION exp {fprintf(file,";R74:\t<exp> ::= <exp> / <exp>\n");			}
			|exp TOK_ASTERISCO exp {fprintf(file,";R75:\t<exp> ::= <exp> * <exp>\n");			}
			|TOK_MENOS exp {fprintf(file,";R76:\t<exp> ::= - <exp>\n");			}
			|exp TOK_AND exp { fprintf(file,";R77:\t<exp> ::= <exp> && <exp>\n");			}
			|exp TOK_OR exp {			fprintf(file,";R78:\t<exp> ::= <exp> || <exp>\n");			}
			|TOK_NOT exp {			fprintf(file,";R79:\t<exp> ::= ! <exp>\n");			}
			|identificador {			fprintf(file,";R80:\t<exp> ::= <identificador>\n");			}
			|constante {			fprintf(file,";R81:\t<exp> ::= <constante>\n");
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
        apilar_constante(pfasm, $1.valor_entero);

        printf("%d-%d-%d\n",
        $$.tipo,
        $$.es_direccion,
        $1.valor_entero);}
			|TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {			fprintf(file,";R82:\t<exp> ::= ( <exp> )\n");}
			|TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {fprintf(file,";R83:\t<exp> ::= ( <comparacion> )\n");}
			|elemento_vector {fprintf(file,";R85:\t<exp> ::= <elemento_vector>\n");}
			|identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO { fprintf(file,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
      ;
lista_expresiones: 	exp resto_lista_expresiones {
			fprintf(file,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
			}
			|{
			fprintf(file,";R90:\t<lista_expresiones> ::=\n");
			};
resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {			fprintf(file,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");			}
			|{			fprintf(file,";R92:\t<resto_lista_expresiones> ::=\n");}
      ;
comparacion: 		 exp TOK_IGUAL exp {			fprintf(file,";R93:\t<comparacion> ::= <exp> == <exp>\n");			}
			| exp TOK_DISTINTO exp {			fprintf(file,";R94:\t<comparacion> ::= <exp> != <exp>\n");			}
			| exp TOK_MENORIGUAL exp {			fprintf(file,";R95:\t<comparacion> ::= <exp> <= <exp>\n");			}
			| exp TOK_MAYORIGUAL exp {			fprintf(file,";R96:\t<comparacion> ::= <exp> >= <exp>\n");			}
			| exp TOK_MENOR exp {			fprintf(file,";R97:\t<comparacion> ::= <exp> < <exp>\n");			}
			| exp TOK_MAYOR exp {			fprintf(file,";R98:\t<comparacion> ::= <exp> > <exp>\n");			};
constante   :constante_logica {    			fprintf(file,";R99:\t<constante> ::= <constante_logica>\n");
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
          $$.valor_entero = $1.valor_entero;
      }
  		|constante_entera {
  			fprintf(file,";R100:\t<constante> ::= <constante_entera>\n");
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
      };
constante_logica  : 	TOK_TRUE {
  			fprintf(file,"R102:\t<constante_logica> ::= true\n");
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
        $$.valor_entero = 1;}
      |TOK_FALSE {
        fprintf(file,"R103:\t<constante_logica> ::= false\n");
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
        $$.valor_entero = 0;
      };
constante_entera  : TOK_CONSTANTE_ENTERA {
                    fprintf(file,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                    $$.tipo = ENTERO;
                    $$.es_direccion = 0;
                    $$.valor_entero = $1.valor_entero;
                  }
identificador     :	TOK_IDENTIFICADOR {
                    fprintf(file,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                    $$ = $1;
                  };
identificador_nuevo         : TOK_IDENTIFICADOR
                          {
                    fprintf(file,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                            /* Añadimos al ambito actual */

                            if (0 == ambito_actual) {
                              INFO_SIMBOLO* info = get_SimbolByID_SoloGlobal($1.lexema);
                             ASSERT_SEMANTICO(NULL == info, "Declaracion duplicada", NULL);

                              ASSERT_SEMANTICO(info == NULL, "Declaracion duplicada", NULL);
                              declarar_global($1.lexema, tipo_actual, clase_actual, tamanio_vector_actual);
                              tamanio_vector_actual = 0;
                            } else {
                                INFO_SIMBOLO* info = uso_solo_local($1.lexema);

                              ASSERT_SEMANTICO(info == NULL, "Declaracion duplicada", NULL);
                                  ASSERT_SEMANTICO(clase_actual != VECTOR, "Variable local de tipo no escalar", NULL);
                              declarar_local($1.lexema, 0, tipo_actual, clase_actual, 0, pos_variable_local_actual);
                              num_variables_locales_actual++;
                             pos_variable_local_actual++;
                            }
                          }
                        ;
/*numero,cola_identificador,alfanumerico,letra,digito*/
%%
void yyerror(char const *s){
	if(aux==0){
		fprintf (stderr,"****Error sintactico en [lin %d, col %d, '%s']\n",row,column, s);
	}else{
		aux=0;
	}
}
