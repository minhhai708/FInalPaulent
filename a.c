#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alfa.h"


extern FILE *yyin;
/*extern FILE *yyout;*/
extern int yyparse(void);
extern FILE *file;
extern FILE *pfasm;

int main(int argc,char *argv[]){
/*
	if (argc < 3){
		fprintf (stderr,"ERROR: Ejecute en terminal:\n\t./alfa <fichero de entrada> <fichero de salida>\n");
		return 1;
	}

*/
	file = fopen("log.txt","w");
	yyin = fopen("ej1.txt","r");
	if (!yyin) {perror("yyin \n"); exit(0);}
	pfasm = fopen("yyin.nasm","w");

	yyparse();

	fclose(yyin);
	fclose(pfasm);
	fclose(file);

	return 0;
}
