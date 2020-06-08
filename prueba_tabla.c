
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.h"


/* Se se carga el primer \n de una cadena. */
static void chomp(char* str)
{
    while (*str != '\0' && *str != '\n') str++;
    *str = '\0';
}

int main(int argc, char** argv)
{
  FILE *in, *out;
  char buffer[256] = {0};
  int ambito_abierto = 0;

  in = fopen(argv[1], "r");
  out = fopen(argv[2], "w");
  /*
  if(!in || !out){
    perror("Error file path\n");
    fclose(in);
    fclose(out);
    exit(1);
  }*/

  iniciar_scope();

  // Leemos linea a linea

  while (1) {
    if (!fgets(buffer, sizeof buffer, in))
      break;

    chomp(buffer);
    if ('\0' == buffer[0]) continue;

    char* ident   = strtok(buffer, "\t\r");
    char* num_str = strtok(NULL,   "\t\r");
    //printf("=> id = '%s' num_str = '%s' \n", ident, num_str);

    // Si no hay numero, buscamos el simbolo
    if (!num_str) {
        INFO_SIMBOLO* inf;
        int val;
        inf = (INFO_SIMBOLO *)get_SimbolByID(ident);
        if (inf)
          val =  get_adicional1_FromSimbolo(inf);
        else
          val = -1;

        fprintf(out, "%s\t%i\n", ident, val);
        continue;
    }

    int num = atoi(num_str);
    // Si hay numero, nos indica que hacer
    if (num == -999) {
      if (strcmp(ident, "cierre") != 0) {
          perror("El numero -999 debe ir con cierre");
          exit(1);
      }
      cerrar_scope_local();
      fprintf(out, "cierre\n");
      ambito_abierto = 0;
    } else {
      if (num < -1) {
        if (ambito_abierto) {
            fprintf(out, "-1\t%s\n", ident);
        } else {
            if (declarar_funcion(ident, ENTERO, num, 0)==ERR) {
                fprintf(out, "-1\t%s\n", ident);
            } else {
                fprintf(out, "%s\n", ident);
                ambito_abierto = 1;
            }
        }
      } else {
        STATUS code;
        if (ambito_abierto) {
            code = declarar_local(ident, VARIABLE, ENTERO, ESCALAR, num, 0);
        } else {
            code = declarar_global(ident, ENTERO, ESCALAR, num);
                    printf("code %d : ", code);
        }
        fprintf(out, (code == OK) ? "%s\n" : "-1\t%s\n", ident);
      }
    }
  }
  liberar_scope();
  fclose(in);
  fclose(out);
  return 0;
}
