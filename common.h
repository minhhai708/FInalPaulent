
#ifndef COMMON_H
#define COMMON_H

#define MAX_TAMANIO_VECTOR 64
#define MAX_LONG_ID 100

/* Retorno de función error/ok */
typedef enum { ERR = -1, OK = 1 } STATUS;

/* Categoría de un símbolo: variable, parámetro de función o función */
typedef enum { VARIABLE = 1, PARAMETRO = 2, FUNCION = 3} CATEGORIA;

/* Tipo de un símbolo: sólo se trabajará con enteros y booleanos */
typedef enum { ENTERO = 1, BOOLEANO =2} TIPO;

/* Clase de un símbolo: pueden ser variables atómicas (escalares) o listas/arrays (vectores) */
typedef enum { ESCALAR= 1, VECTOR = 2} CLASE;


typedef struct{
    char lexema[MAX_LONG_ID+1];
    int valor_entero;
    TIPO tipo;
    int es_direccion;
    int etiqueta;
    int num_parametros_llamada_actual;
} tipo_atributos;

#endif  /* TABLAHASH_H */
