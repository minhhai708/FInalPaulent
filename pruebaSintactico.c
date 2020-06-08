#include <stdio.h>
#include <stdlib.h>
#include "alfa.tab.h"


extern FILE *yyin;
extern int yyparse(void);
extern FILE *file;

int main(int argc,char *argv[]){

    yyin = fopen(argv[1],"r");
    if(!yyin){
        fprintf (stderr,"**Error al abrir el archivo de entrada");
	return -1;
    }

    file = fopen(argv[2],"w");
    if(!file){
        fprintf (stderr,"**Error al abrir el archivo de salida");
	return -1;
    }

    yyparse();
    fclose(yyin);
    fclose(file);
    return 0;
}
