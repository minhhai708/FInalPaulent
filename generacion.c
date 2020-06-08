/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "generacion.h"
/*
   Código para el principio de la sección .bss.
   Con seguridad sabes que deberás reservar una variable entera para guardar
 *  el puntero de pila extendido (esp). Se te sugiere el nombre __esp
 *  para esta variable.
*/
void escribir_cabecera_bss(FILE* fpasm) {
    fprintf(fpasm, "%s\n", "segment .bss");
    fprintf(fpasm, "\t%s\n", "__esp resd 1");

}

void escribir_subseccion_data(FILE* fpasm) {

    fprintf(fpasm, "%s\n", "segment .data");
    fprintf(fpasm, "\t%s\n", "__msg_error_division\tdb \"****Error de ejecuccion: Division por cero.\", 0");
    fprintf(fpasm, "\t%s\n", "__msg_error_indice_vector\tdb \"****Error de ejecuccion: Indice es fuera de rango.\", 0");
    fprintf(fpasm, "\t%s\n", "__msg_debug\tdb \"****RUN HERE.\", 0");

}

void declarar_variable(FILE* fpasm, char * nombre, TIPO tipo, int tamano) {
    if (tipo == ENTERO || tipo == BOOLEANO)
        fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
        fprintf(fpasm, "%s\n","segment .text");
        fprintf(fpasm, "\t%s\n","global main");
        fprintf(fpasm, "\t%s\n","extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean");
        fprintf(fpasm, "\t%s\n", "extern print_endofline, print_blank, print_string");
        fprintf(fpasm, "\t%s\n","extern alfa_malloc, alfa_free, ld_float");
}
/*
 * Para escribir el comienzo del segmento .text, básicamente se indica que se exporta la etiqueta main y que se usarán las funciones declaradas en la librería alfalib.o
*/

void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "%s\n","main:");
  fprintf(fpasm, "\t%s\n","mov dword [__esp] , esp");

}
/*
   En este punto se debe escribir, al menos, la etiqueta main y la sentencia que guarda el puntero de pila en su variable (se recomienda usar __esp).
*/

void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "\n\t%s\n",";Final of Progrma");


  fprintf(fpasm, "\t%s\n","jmp near fin");

  fprintf(fpasm, "%s\n","fin_error_division:");
  fprintf(fpasm, "\t%s\n","push dword __msg_error_division");
  fprintf(fpasm, "\t%s\n","call print_string");
  fprintf(fpasm, "\t%s\n","add esp, 4");
  fprintf(fpasm, "\t%s\n","call print_endofline");
  fprintf(fpasm, "\t%s\n","jmp near fin");

  fprintf(fpasm, "%s\n","fin_indice_fuera_rango:");
  fprintf(fpasm, "\t%s\n","push dword __msg_error_indice_vector");
  fprintf(fpasm, "\t%s\n","call print_string");
  fprintf(fpasm, "\t%s\n","add esp, 4");
  fprintf(fpasm, "\t%s\n","call print_endofline");
  fprintf(fpasm, "\t%s\n","jmp near fin");

  fprintf(fpasm, "%s\n","fin:");
  fprintf(fpasm, "\t%s\n","mov dword esp, [__esp]");
  fprintf(fpasm, "\t%s\n","ret");

}


void escribir_operando(FILE* fpasm, char* nombre, int es_variable){

  fprintf(fpasm, "\n\t%s\n",";Escribe Operando");
  if (es_variable)
    fprintf(fpasm, "\tpush dword [_%s]\n",nombre);
  else
    fprintf(fpasm, "\tpush dword %s\n",nombre);

}
/*
Función que debe ser invocada cuando se sabe un operando de una operación
aritmético-lógica y se necesita introducirlo en la pila.
- nombre es la cadena de caracteres del operando tal y como debería aparecer
en el fuente NASM
- es_variable indica si este operando es una variable (como por ejemplo b1)
con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el
primer caso internamente se representará como _b1 y, sin embargo, en el
segundo se representará tal y como esté en el argumento (34).
*/
void asignar(FILE* fpasm, char* nombre, int es_variable){
    fprintf(fpasm, "\n\t%s\n",";Asignar valor");
    fprintf(fpasm, "\tpop dword eax\n");
    if (!es_variable)
      fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);
    else
      fprintf(fpasm,"\t%s\n", "mov eax, dword [eax]");
}

void asignar_vector(FILE *fpasm, int es_variable)
{
    fprintf(fpasm, "\n\t%s\n",";Asignacion a elemento del vector");
    fprintf(fpasm, "\tpop dword eax\n");
    if (!es_variable)
        fprintf(fpasm, "\n\t%s\n","mov eax,dword [eax]");
    /* Posicion del vector */
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tmov dword [ebx], eax\n");
}
/*
- Genera el código para asignar valor a la variable de nombre nombre.
- Se toma el valor de la cima de la pila.
- El último argumento es el que indica si lo que hay en la cima de la pila es
una referencia (1) o ya un valor explícito (0).
*/
/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
En todas ellas se realiza la operación como se ha resumido anteriormente:
- Se extrae de la pila los operandos
- Se realiza la operación
- Se guarda el resultado en la pila
Los dos últimos argumentos indican respectivamente si lo que hay en la pila es
una referencia a un valor o un valor explícito.
Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido
sí hay que mencionar explícitamente que, en el caso de la división, se debe
controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error
controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno
que no se produce “Segmentation Fault”)
*/
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
    fprintf(fpasm, "\n\t%s\n",";SUMA");
    fprintf(fpasm, "\t%s\n","pop dword eax");
    fprintf(fpasm, "\t%s\n","pop dword ebx");
    /*
    if (!es_variable_1 && es_variable_2){
      fprintf(fpasm, "\t%s\n","add eax, [ebx]");
    }else{
      if (!es_variable_1){
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
      }
      if (!es_variable_2)
        fprintf(fpasm, "\t%s\n","add eax, [ebx]");
      else
        fprintf(fpasm, "\t%s\n","add eax, ebx");
    }
    */
    fprintf(fpasm, "\t%s\n","add eax, ebx");
    fprintf(fpasm, "\t%s\n","push dword eax");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
    fprintf(fpasm, "\t%s\n",";MULTIPLICAR");
    fprintf(fpasm, "\t%s\n","pop dword eax");
    fprintf(fpasm, "\t%s\n","pop dword ebx");

    if (!es_variable_2)
      fprintf(fpasm, "\t%s\n","imul eax, ebx");
    else
      fprintf(fpasm, "\t%s\n","imul eax, ebx");
    fprintf(fpasm, "\t%s\n","push dword eax");
}/*1*/

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  if (es_variable_1 && es_variable_2){
    fprintf(fpasm, "\t%s\n","pop dword eax");
    fprintf(fpasm, "\t%s\n","pop dword ebx");
    fprintf(fpasm, "\t%s\n","or eax, ebx");
    fprintf(fpasm, "\t%s\n\n","push dword eax");
  }
}

void cambiar_signo(FILE* fpasm, int es_variable){
  fprintf(fpasm, "\n\t%s\n",";Cambio de signo");

  fprintf(fpasm, "\t%s\n","pop dword eax");
  if (!es_variable){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }
  fprintf(fpasm, "\t%s\n\n","neg dword eax");
  fprintf(fpasm, "\t%s\n\n","push dword eax");
}/*1*/


/*
Función aritmética de cambio de signo.
Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya
que sólo usa un operando.
*/
void no(FILE* fpasm, int es_variable, int cuantos_no){
    fprintf(fpasm, "\n\t%s\n",";Cambiar monádica lógica de negación");
    fprintf(fpasm, "\t%s\n","pop eax");
    if (es_variable)
      fprintf(fpasm, "\tcmp dword %s, 0\n","eax");
    else
      fprintf(fpasm, "\tcmp dword %s, 0\n","eax");
    fprintf(fpasm, "\tje __one_%d\n",cuantos_no);
    fprintf(fpasm, "\t%s\n","push dword 0");
    fprintf(fpasm, "\tjmp __end_not_%d\n",cuantos_no);
    fprintf(fpasm, "__one_%d:\n",cuantos_no);
    fprintf(fpasm, "\t%s\n","push dword 1");
    fprintf(fpasm,"__end_not_%d:\n", cuantos_no);

}


/*
Función monádica lógica de negación. No hay un código de operación de la ALU
que realice esta operación por lo que se debe codificar un algoritmo que, si
encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas,
la implementación del algoritmo requerirá etiquetas). Véase en los ejemplos de
programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/

/* FUNCIONES COMPARATIVAS */
/*
Todas estas funciones reciben como argumento si los elementos a comparar son o
no variables. El resultado de las operaciones, que siempre será un booleano (“1”
si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el
resto de operaciones. Se deben usar etiquetas para poder gestionar los saltos
necesarios para implementar las comparaciones.
*/

void leer(FILE* fpasm, char* nombre, TIPO tipo){
  fprintf(fpasm, "\n\t%s\n",";Lee input");
  fprintf(fpasm, "\tpush dword _%s\n", nombre);
  if (tipo == ENTERO)
    fprintf(fpasm, "\tcall scan_int\n");
  else if (tipo == BOOLEANO)
    fprintf(fpasm, "\tcall scan_boolean\n");
  fprintf(fpasm, "\tadd esp, 4\n");
}

void leer_ya_apilado(FILE* fpasm, int tipo)
{
    fprintf(fpasm, "\n\t;Lectura de un input a direccion ya apilada\n");

    /* Si tipo no es ENTERO o BOLEANO habria error, pero simplemente llama a scan_boolean */
    fprintf(fpasm, "\tcall %s\n", (tipo == ENTERO) ? "scan_int" :"scan_boolean");
    fprintf(fpasm, "\tadd esp, 4\n");
}

void escribir(FILE* fpasm, int es_variable, TIPO tipo){
  fprintf(fpasm, "\n\t%s\n",";Escribe output");

  if (tipo == ENTERO)
    fprintf(fpasm,"\t%s\n", "call print_int");
  else if (tipo == BOOLEANO)
    fprintf(fpasm,"\t%s\n", "call print_boolean");

  fprintf(fpasm,"\t%s\n", "add esp, 4");
  fprintf(fpasm,"\t%s\n", "call print_endofline");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t%s\n",";RESTA");
  fprintf(fpasm, "\t%s\n","pop dword ebx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","sub eax, ebx");
  fprintf(fpasm, "\t%s\n","push dword eax");
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t%s\n",";DIVISION");
  fprintf(fpasm, "\t%s\n","pop dword ecx");
  fprintf(fpasm, "\t%s\n","pop dword eax");

  fprintf(fpasm, "\t%s\n","cmp ecx, 0");
  fprintf(fpasm, "\t%s\n","je fin_error_division");

  fprintf(fpasm, "\t%s\n","cdq");
  fprintf(fpasm, "\t%s\n","idiv ecx");
  fprintf(fpasm, "\t%s\n","push dword eax");
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t%s\n",";AND");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","pop dword ebx");


  fprintf(fpasm, "\t%s\n","and eax, ebx");
  fprintf(fpasm, "\t%s\n\n","push dword eax");

}


void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";IGUAL");

  fprintf(fpasm, "\t%s\n","pop dword edx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","cmp eax, edx");

  fprintf(fpasm, "\tje _igual_%d\n", etiqueta);
  fprintf(fpasm, "_not_igual_%d:\n", etiqueta);

  fprintf(fpasm, "\t%s\n","push dword 0");
  fprintf(fpasm, "\tjmp _igual_fin_%d\n", etiqueta);
  fprintf(fpasm, "_igual_%d:\n", etiqueta);
  fprintf(fpasm, "\t%s\n","push dword 1");
  fprintf(fpasm, "_igual_fin_%d:\n", etiqueta);
}
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";DISTINTO");

  fprintf(fpasm, "\t%s\n","pop dword edx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","cmp eax, edx");

  fprintf(fpasm, "\tjne _distinto_%d\n", etiqueta);
  fprintf(fpasm, "_not_distinto_%d:\n", etiqueta);

  fprintf(fpasm, "\t%s\n","push dword 0");
  fprintf(fpasm, "\tjmp _distinto_fin_%d\n", etiqueta);
  fprintf(fpasm, "_distinto_%d:\n", etiqueta);
  fprintf(fpasm, "\t%s\n","push dword 1");
  fprintf(fpasm, "_distinto_fin_%d:\n", etiqueta);
}
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";MENOR IGUAL");

  fprintf(fpasm, "\t%s\n","pop dword edx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","cmp eax, edx");

  fprintf(fpasm, "\tjle _menor_igual_%d\n", etiqueta);
  fprintf(fpasm, "_not_menor_igual_%d:\n", etiqueta);

  fprintf(fpasm, "\t%s\n","push dword 0");
  fprintf(fpasm, "\tjmp _menor_igual_fin_%d\n", etiqueta);
  fprintf(fpasm, "_menor_igual_%d:\n", etiqueta);
  fprintf(fpasm, "\t%s\n","push dword 1");
  fprintf(fpasm, "_menor_igual_fin_%d:\n", etiqueta);
}
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";MAYOR IGUAL");

  fprintf(fpasm, "\t%s\n","pop dword edx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","cmp eax, edx");

  fprintf(fpasm, "\tjge _mayor_igual_%d\n", etiqueta);
  fprintf(fpasm, "_not_mayor_igual_%d:\n", etiqueta);

  fprintf(fpasm, "\t%s\n","push dword 0");
  fprintf(fpasm, "\tjmp _mayor_igual_fin_%d\n", etiqueta);
  fprintf(fpasm, "_mayor_igual_%d:\n", etiqueta);
  fprintf(fpasm, "\t%s\n","push dword 1");
  fprintf(fpasm, "_mayor_igual_fin_%d:\n", etiqueta);
}
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";MENOR");

  fprintf(fpasm, "\t%s\n","pop dword edx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","cmp eax, edx");

  fprintf(fpasm, "\tjl _menor_%d\n", etiqueta);
  fprintf(fpasm, "_not_menor_%d:\n", etiqueta);

  fprintf(fpasm, "\t%s\n","push dword 0");
  fprintf(fpasm, "\tjmp _menor_fin_%d\n", etiqueta);
  fprintf(fpasm, "_menor_%d:\n", etiqueta);
  fprintf(fpasm, "\t%s\n","push dword 1");
  fprintf(fpasm, "_menor_fin_%d:\n", etiqueta);
}
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";MAYOR");
  fprintf(fpasm, "\t%s\n","pop dword edx");
  fprintf(fpasm, "\t%s\n","pop dword eax");
  fprintf(fpasm, "\t%s\n","cmp eax, edx");

  fprintf(fpasm, "\tjg _mayor_%d\n", etiqueta);
  fprintf(fpasm, "_not_mayor_%d:\n", etiqueta);

  fprintf(fpasm, "\t%s\n","push dword 0");
  fprintf(fpasm, "jmp _mayor_fin_%d\n", etiqueta);
  fprintf(fpasm, "_mayor_%d:\n", etiqueta);
  fprintf(fpasm, "\t%s\n","push dword 1");
  fprintf(fpasm, "_mayor_fin_%d:\n", etiqueta);
}

/**WEEK 2*******************************/

/*
• Generación de código para el inicio de una estructura while
• Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
• exp_es_variable
    ◦ Es 1 si la expresión de la condición es algo asimilable a una variable (identificador, elemento de vector)
    ◦ Es 0 en caso contrario (constante u otro tipo de expresión)
*/
void while_inicio(FILE * fpasm, int etiqueta)
{
  fprintf(fpasm, "\n\t%s\n",";WHILE INICIO");
  fprintf(fpasm, "_while_inicio_%d:\n",etiqueta);
}
/*
  • Generación de código para el momento en el que se ha generado el código de la expresión de control del bucle
  • Sólo necesita usar la etiqueta adecuada, por lo que sólo se necesita que se recupere el valor de la etiqueta que corresponde al momento actual.
  • exp_es_variable
      ◦ Es 1 si la expresión de la condición es algo asimilable a una variable (identificador, o elemento de vector)
      ◦ Es 0 en caso contrario (constante u otro tipo de expresión)
*/
void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta)
{
  fprintf(fpasm, "\n\t%s\n",";WHILE EXP PILA");
  fprintf(fpasm, "_while_exp_pila_%d:\n",etiqueta);
  fprintf(fpasm, "\t%s\n", "pop dword eax");
  fprintf(fpasm, "\t%s\n", "cmp eax , 0");
  fprintf(fpasm, "\tje _while_fin_%d\n", etiqueta);
}
/*
  • Generación de código para el final de una estructura while
  • Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca según se ha explicado
  • Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas puesto que se ha liberado la última de ellas.
*/
void while_fin( FILE * fpasm, int etiqueta)
{
  fprintf(fpasm, "\n\t%s\n",";WHILE FIN");
  fprintf(fpasm, "\tjmp _while_inicio_%d\n",etiqueta);
  fprintf(fpasm, "_while_fin_%d:\n",etiqueta);
}

/*
• Generación de código para el inicio de una estructura if-then-else
• Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
• exp_es_variable
  ◦ Es 1 si la expresión de la condición es algo asimilable a una variable (identificador, elemento de vector)
  ◦ Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta)
{
  fprintf(fpasm, "\n\t%s\n",";IF THEN ELSE INICIO");
  fprintf(fpasm, "\t%s\n", "pop dword eax");
  fprintf(fpasm, "\t%s\n", "cmp eax , 0");
  fprintf(fpasm, "\tje _ifthenelse_else_inicion_%d\n", etiqueta);
}
/*
• Generación de código para el fin de la rama then de una estructura if-then-else
• Sólo necesita usar la etiqueta adecuada, aunque es el final de una rama, luego debe venir otra (la rama else) antes de que se termine la estructura y se tenga que ajustar las etiquetas por lo que sólo se necesita que se utilice la etiqueta que corresponde al momento actual.
*/
void ifthenelse_fin_then( FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\n\t%s\n",";IF THEN ELSE INICIO");
  fprintf(fpasm, "\tjmp _ifthenelse_fin_%d\n", etiqueta);
  fprintf(fpasm, "_ifthenelse_else_inicion_%d:\n",etiqueta);

}

/*
• Generación de código para el fin de una estructura if-then-else
• Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca según se ha explicado
• Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas puesto que se ha liberado la última de ellas.
*/
void ifthenelse_fin( FILE * fpasm, int etiqueta)/*1*/
{
  fprintf(fpasm, "\n\t%s\n",";IF THEN ELSE FINAL");
  fprintf(fpasm, "_ifthenelse_fin_%d:\n",etiqueta);
}

/*
• Generación de código para el inicio de una estructura if-then
• Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
• exp_es_variable
    ◦ Es 1 si la expresión de la condición es algo asimilable a una variable (identificador, elemento de vector)
    ◦ Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta)
{
  fprintf(fpasm, "\n\t%s\n",";IF THEN INICIO");
  fprintf(fpasm, "\t%s\n", "pop dword eax");
  fprintf(fpasm, "\t%s\n", "cmp eax , 0");
  fprintf(fpasm, "\tje _ifthen_fin_%d\n", etiqueta);
}

/*
• Generación de código para el fin de una estructura if-then
• Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca según se ha explicado
• Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas puesto que se ha liberado la última de ellas.
*/

void ifthen_fin(FILE * fpasm, int etiqueta)/*1*/
{
  fprintf(fpasm, "\n\t%s\n",";IF THEN ELSE FINAL");
  fprintf(fpasm, "_ifthen_fin_%d:\n",etiqueta);
}
/*
• Generación de código para indexar un vector
    ◦ Cuyo nombre es nombre_vector
    ◦ Declarado con un tamaño tam_max
    ◦ La expresión que lo indexa está en la cima de la pila
    ◦ Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
    ◦ Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
• Según se especifica en el material, es suficiente con utilizar dos registros para realizar esta tarea.
*/
void escribir_elemento_vector(FILE * fpasm, char * nombre_vector, int tam_max, int exp_es_direccion){
  fprintf(fpasm, "\n\t%s\n",";ESCRIBIR ELEMENTO VECTOR");
  fprintf(fpasm, "\t%s\n", "pop dword eax");
  fprintf(fpasm, "\t%s\n", "pop dword ebx");
  fprintf(fpasm, "\tcmp eax , %d\n", tam_max-1);
  fprintf(fpasm, "\tjg fin_indice_fuera_rango\n");
  fprintf(fpasm, "\tcmp eax , %d\n", 0);
  fprintf(fpasm, "\tjl fin_indice_fuera_rango\n");
  fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
  fprintf(fpasm, "\t%s\n", "lea ebx, [edx + eax*4]");
  fprintf(fpasm, "\t%s\n", "push dword eax");
}

void debug(FILE * fpasm){
  fprintf(fpasm, "\n\t%s\n", ";DEBUG");
  fprintf(fpasm, "\t%s\n", "push dword __msg_debug");
  fprintf(fpasm, "\t%s\n", "call print_string");
  fprintf(fpasm, "\t%s\n", "add esp, 4");
  fprintf(fpasm, "\t%s\n", "call print_endofline");
}


/*
  • Generación de código para el retorno de una función.
      ◦ La expresión que se retorna está en la cima de la pila.
      ◦ Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
      ◦ Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
*/
void retornarFuncion(FILE * fpasm, int es_variable)
{
    fprintf(fpasm, "\n\t%s\n", ";RETORNAR FUNCION");
  fprintf(fpasm, "\t%s\n", "mov esp, ebp");
  fprintf(fpasm, "\t%s\n", "pop ebp");
  fprintf(fpasm, "\t%s\n", "ret");
}

/*
Función para dejar en la cima de la pila la dirección efectiva del parámetro que ocupa la posición
pos_parametro (recuerda que los parámetros se ordenan con origen 0) de un total de num_total_parametros

*/
void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros)
{
  fprintf(fpasm, "\n\t%s\n", ";ESCRIBIR PARAMETRO");
  fprintf(fpasm, "\tlea eax, [ebp + %d]\n",(4 + 4*(num_total_parametros - pos_parametro)));
  fprintf(fpasm, "\t%s\n","mov eax, [eax]");
  fprintf(fpasm, "\t%s\n","push eax");
}

/*
    • Función para dejar en la cima de la pila la dirección efectiva de la variable
     local que ocupa la posición posicion_variable_local (recuerda que ordenadas con origen 1)
*/
void escribirVariableLocal(FILE* fpasm, int direccion, int posicion_variable_local)
{
  fprintf(fpasm, "\n\t%s\n", ";ESCRIBIR VARIABLE LOCAL");
  fprintf(fpasm, "\tlea eax, [ebp - %d]\n",4*posicion_variable_local);
  fprintf(fpasm, "\t%s\n","push eax");

}


/*

    • Función para poder asignar a un destino que no es una
    variable “global” (tipo _x) por ejemplo
    parámetros o variables globales (ya que en ese caso su nombre
     real de alto nivel, no se tiene en cuenta pues es realmente
     un desplazamiento a partir de ebp: ebp+4 o ebp-8 por ejemplo.
    • Se debe asumir que en la pila estará
        ◦ Primero (en la cima) lo que hay que asignar
        ◦ Debajo (se ha introducido en la pila antes) la
         dirección donde hay que asignar
    • es_variable
        ◦ Es 1 si la expresión que se va a asignar es algo asimilable a una variable (identificador, o elemento de vector)
        ◦ Es 0 en caso contrario (constante u otro tipo de expresión)
*/
void asignarDestinoEnPila(FILE* fpasm, int es_variable)
{
  fprintf(fpasm, "\n\t%s\n", ";ESCRIBIR VARIABLE LOCAL");
  fprintf(fpasm, "\t%s\n","pop eax");
  fprintf(fpasm, "\t%s\n","pop ebx");
  fprintf(fpasm, "\t%s\n","mov [eax], ebx");
}

/*
  • Como habrás visto en el material, nuestro convenio de llamadas a las
    funciones asume que los argumentos se pasan por valor, esto significa que siempre se dejan en la pila “valores” y no “variables”
  • Esta función realiza la tarea de dado un operando escrito en la pila y sabiendo si
    es variable o no (es_variable) se deja en la pila el valor correspondiente
*/
void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){
      fprintf(fd_asm, "\n\t%s\n", ";OPERANDO EN PILA A ARGUMENTO");
}

/*
    • Esta función genera código para llamar a la
      función nombre_funcion asumiendo que los argumentos están
      en la pila en el orden fijado en el material de la asignatura.
    • Debe dejar en la cima de la pila el retorno de la función tras haberla limpiado de sus argumentos
    • Para limpiar la pila puede utilizar la función de nombre limpiarPila

*/
void llamarFuncion(FILE * fpasm, char * nombre_funcion, int num_argumentos){
  fprintf(fpasm, "\n\t%s\n", ";LLAMAR FUNCION");
  fprintf(fpasm, "\tcall _%s\n", nombre_funcion);
  fprintf(fpasm, "\tadd esp, %d\n", 4*num_argumentos);
  fprintf(fpasm, "\t%s\n", "push dword eax");
}

/*
    • Genera código para limpiar la pila tras invocar una función
    • Esta función es necesaria para completar la llamada a métodos,
      su gestión dificulta el conocimiento por parte de la función de llamada
      del número de argumentos que hay en la pila
*/
void limpiarPila(FILE * fd_asm, int num_argumentos){
  fprintf(fd_asm, "\n\t%s\n", ";LIMPIAR PILAS");
  fprintf(fd_asm, "\tadd esp, %d\n", num_argumentos*4);
}
void apilar_constante(FILE* fpasm, int valor)
{
  fprintf(fpasm, "\n\t;Apilar la constante %i\n",valor);
  fprintf(fpasm, "\tpush dword %i\n",valor);
}

void apilar_valor(FILE* fpasm, int es_referencia)
{
    if (es_referencia) {
      fprintf(fpasm, "\n\t%s\n",";Apilar el valor para pasar parametro a funcion");
      fprintf(fpasm, "\t%s\n", "pop dword ebx");
      fprintf(fpasm, "\t%s\n", "mov ebx, [ebx]");
      fprintf(fpasm, "\t%s\n", "push dword ebx");
    }
    /* Si no es referencia no se hace nada pues ya esta en pila */
}

/*
  • Generación de código para iniciar la declaración de una función.
  • Es necesario proporcionar
      ◦ Su nombre
      ◦ Su número de variables locales
*/
void declararFuncion(FILE * fpasm, char * nombre_funcion, int num_var_loc)
{
    fprintf(fpasm, "\n\t;DECLARAR FUNCION nombre_funcion=%s,num_var_loc=%d\n", nombre_funcion, num_var_loc);
    fprintf(fpasm, "_%s:\n", nombre_funcion);
    fprintf(fpasm, "\t%s\n", "push ebp");
    fprintf(fpasm, "\t%s\n", "mov ebp, esp");
    fprintf(fpasm, "\tsub esp, %d\n", num_var_loc*4);
}
