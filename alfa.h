#ifndef _ALFA_H
#define _ALFA_H
#include "tablaSimbolos.h"
#include "generacion.h"
#include "tablaHash.h"


int error_semantico();
int error_semantico_duplicada();
int error_semantico_funcion_retorno(char *lexema);
int error_semantico_asignacion();
int error_semantico_variable(char *lexema);
int error_semantico_index_entero();
int error_semantico_index_vector();
int error_semantico_condicion_int();
int error_semantico_bucle_int();
int error_semantico_escalar(char * lexema);
int error_semantico_funcion_tipo();
int error_semantico_funcion_ret();
int error_semantico_aritmetico();
int error_semantico_identificador_escalar(char * lexema);
int error_semantico_tipo_funcion(char * lexema);
int error_semantico_funcion_parametro();
int error_semantico_comparacion();
int error_semantico_tamano_vector(int tamano);
int error_semantico_local_escalar();
int error_semantico_parametros();


#endif
