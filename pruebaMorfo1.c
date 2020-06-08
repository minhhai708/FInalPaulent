#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tokens.h"


char * tokACadena(int code);

int main(int argc, char *argv[]){

  FILE *salida = NULL;/**/
  extern int yylex();
  extern char* yytext;
  extern int row;
  extern int column;
  extern FILE *yyin;/*yyin*/
  int tok;
  
  if(argc != 3){
    fprintf(stdout, "Fallo en argumentos de entrada entrada\n");
    return -1;
  }

  yyin = fopen(argv[1], "r");
  if(yyin == NULL){
    fprintf(stdout, "Fallo en fichero de entrada\n");
    return -1;
  }
  salida = fopen(argv[2], "w");
  if(salida == NULL){
    fprintf(stdout, "Fallo en fichero de salida\n");
    return -1;
  }
  

  for (tok = yylex();tok != 0;tok = yylex()){
    if(tok == TOK_ERROR){
      if(strlen(yytext)>100){
        fprintf (stderr,"****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",row,(int)(column-strlen(yytext)),yytext);
      }else if(strlen(yytext) == 1){
        fprintf (stderr,"****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",row,(int)(column-strlen(yytext)),yytext);
      }
      break;
    }
    fprintf (salida,"%s\t%d\t%s\n",tokACadena(tok),tok,yytext);
    
  }

  fclose(salida);
  fclose(yyin);
  return 0;

}


char * tokACadena(int code){
  
  if (code == 100){
    return "TOK_MAIN";
  }
    
  else if(code == 101){
    return "TOK_INT";
  }
  else if(code == 102){
    return "TOK_BOOLEAN";
  }
  else if(code == 103){
    return "TOK_ARRAY";
  }
  else if(code == 104){
    return "TOK_FUNCTION";
  }
  else if(code == 105){
    return "TOK_IF";
  }
  else if(code == 106){
    return "TOK_ELSE";
  }
  else if(code == 107){
    return "TOK_WHILE";
  }
  else if(code == 108){
    return "TOK_SCANF";
  }
  else if(code == 109){
    return "TOK_PRINTF";
  }
  else if(code == 110){
    return "TOK_RETURN";
  }
  /**/
  else if(code == 200){
    return "TOK_PUNTOYCOMA";
  }
  else if(code == 201){
    return "TOK_COMA";
  }
  else if(code == 202){
    return "TOK_PARENTESISIZQUIERDO";
  }
  else if(code == 203){
    return "TOK_PARENTESISDERECHO";
  }
  else if(code == 204){
    return "TOK_CORCHETEIZQUIERDO";
  }
  else if(code == 205){
    return "TOK_CORCHETEDERECHO";
  }
  else if(code == 206){
    return "TOK_LLAVEIZQUIERDA";
  }
  else if(code == 207){
    return "TOK_LLAVEDERECHA";
  }
  else if(code == 208){
    return "TOK_ASIGNACION";
  }
  else if(code == 209){
    return "TOK_MAS";
  }
  else if(code == 210){
    return "TOK_MENOS";
  }
  else if(code == 211){
    return "TOK_DIVISION";
  }
  else if(code == 212){
    return "TOK_ASTERISCO";
  }
  else if(code == 213){
    return "TOK_AND";
  }
  else if(code == 214){
    return "TOK_OR";
  }
  else if(code == 215){
    return "TOK_NOT";
  }
  else if(code == 216){
    return "TOK_IGUAL";
  }
  else if(code == 217){
    return "TOK_DISTINTO";
  }
  else if(code == 218){
    return "TOK_MENORIGUAL";
  }
  else if(code == 219){
    return "TOK_MAYORIGUAL";
  }
  else if(code == 220){
    return "TOK_MENOR";
  }
  else if(code == 221){
    return "TOK_MAYOR";
  }
  /**/
  else if(code == 300){
    return "TOK_IDENTIFICADOR";
  }
  /**/
  else if(code == 400){
    return "TOK_CONSTANTE_ENTERA";
  }
  else if(code == 401){
    return "TOK_TRUE";
  }
  else if(code == 402){
    return "TOK_FALSE";
  }
  /**/
  else if(code == -1){
    return "TOK_ERROR";
  }

  else
    return NULL;


  return NULL;
}
