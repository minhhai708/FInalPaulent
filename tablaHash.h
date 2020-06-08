/*
 * Fichero: tablaHash.h
 * Autor: MINH HAI LE
 * Curso: 2019-2020
 */

#ifndef TABLAHASH_H
#define TABLAHASH_H


#include <stdio.h>
#include "common.h"

/**************** CONSTANTES ****************/

#define POS_INI_PARAMS 0        /* posición de inicio de parámetros de función (empiezan a contar en 0) */
#define POS_INI_VARS_LOCALES 1  /* posición de inicio de variables locales de función (empiezan a contar en 1) */

#define HASH_CODE_INI 1
#define HASH_CODE_FACTOR 7

/* Información de un símbolo */
typedef struct _INFO_SIMBOLO {
    char* lexema;
    CATEGORIA categoria;
    TIPO tipo;
    CLASE clase;
    int adicional1;
    int adicional2;
    struct _INFO_SIMBOLO* next;
}INFO_SIMBOLO;

typedef struct _NODO_HASH {
    INFO_SIMBOLO* info;      /* información del símbolo */
    struct _NODO_HASH* next;    /* puntero al siguiente nodo*/
}NODO_HASH;

typedef struct _TABLA_HASH {
    int tam;            /* tamaño de la tabla hash */
    NODO_HASH** tabla;  /* tabla */
    INFO_SIMBOLO* simbolos; /* Lista enlazada con todos los info_simbolos */
}TABLA_HASH;

/**************** FUNCIONES ****************/

INFO_SIMBOLO* crear_info_simbolo(const char* lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2);
void liberar_info_simbolo(INFO_SIMBOLO* is);

NODO_HASH* crear_nodo(INFO_SIMBOLO* is);

void liberar_nodo(NODO_HASH* nh);

TABLA_HASH* crear_tabla(int tam);

void liberar_tabla(TABLA_HASH* th);

unsigned long hash(const char* str);

INFO_SIMBOLO* buscar_simbolo(const TABLA_HASH* th, const char* lexema);

STATUS insertar_simbolo(TABLA_HASH* th, const char* lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2);

void borrar_simbolo(TABLA_HASH* th, const char* lexema);

int modificar_simbolo(INFO_SIMBOLO * sim,const char *lexema, CATEGORIA categoria, TIPO tipo, CLASE clase, int adicional1, int adicional2);



INFO_SIMBOLO* lista_simbolos(const TABLA_HASH* th);
int get_adicional1_FromSimbolo(INFO_SIMBOLO * is);
int get_adicional2_FromSimbolo(INFO_SIMBOLO * is);
#endif  /* TABLAHASH_H */
