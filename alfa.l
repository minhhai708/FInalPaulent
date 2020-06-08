%{

#include <stdio.h>
#include <string.h>
/*#include "tokens.h", commented for syntactic*/
/*added for syntactic*/
#include "common.h"
#include "alfa.tab.h"

FILE *file;
int fileno(FILE *stream);

int column=0;
int row=1;
int aux=0;

void error_morfologico(){

	fprintf (stderr,"****Error en [lin %d, col %d]: simbolo no permitido (%c)\n",row,column,yytext[0]);
	aux=1;
}

void error_morfologico1(){

	fprintf (stderr,"****Error en [lin %d, col %d]: identificador demasiado largo(%s)\n",row,column,yytext);
	aux=1;
}
%}

IDENTIFICADOR [a-zA-Z]([a-zA-Z]|[0-9])*
NUMEROS ([0-9])+
SALTO [\r\n]|[\n\r]|[\n]

%option noyywrap
%option nounput
%option noinput

%%

"main"       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MAIN; }

"int"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_INT; }

"boolean"    { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_BOOLEAN; }

"array"      { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_ARRAY; }

"function"   { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_FUNCTION; }

"if"         { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_IF; }

"else"       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_ELSE; }

"while"     { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_WHILE; }

"scanf"      { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_SCANF; }

"printf"    { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_PRINTF; }

"return"   { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_RETURN; }

"true"       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_TRUE; }

"false"      { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_FALSE; }

"error"      { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_ERROR; }

";"      { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_PUNTOYCOMA; }

","     { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_COMA; }

"("        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_PARENTESISIZQUIERDO; }

")"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_PARENTESISDERECHO; }

"["        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_CORCHETEIZQUIERDO; }

"]"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_CORCHETEDERECHO; }

"{"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_LLAVEIZQUIERDA; }

"}"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_LLAVEDERECHA; }

"="        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_ASIGNACION; }

"+="       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MASIGUAL; }

"+"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MAS; }

"-"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MENOS; }

"/"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_DIVISION; }

"*"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_ASTERISCO; }

"&&"       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_AND; }

"||"       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_OR; }

"!"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_NOT; }

"=="       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_IGUAL; }

"!="       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_DISTINTO; }

"<="       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MENORIGUAL; }

">="       { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MAYORIGUAL; }

"<"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MENOR; }

">"        { column += yyleng; fprintf(file,";D:\t%s\n",yytext); return TOK_MAYOR; }

" "         {
            column =  column + yyleng;

            }
"\t" {
            column= column + yyleng;
            }
"//".* { }


({IDENTIFICADOR})  {
                    column =  column + yyleng;

                    if (yyleng>100) {
			error_morfologico1();
                        return TOK_ERROR;
                    }else{
                        fprintf(file,";D:\t%s\n",yytext);
                        strcpy(yylval.atributos.lexema,yytext);
                        return TOK_IDENTIFICADOR;
                        }
                    }

{NUMEROS} {
            column =  column + yyleng;
            yylval.atributos.valor_entero = atoi(yytext);
            fprintf(file,";D:\t%d\n",yylval.atributos.valor_entero);
            return TOK_CONSTANTE_ENTERA;
            }



.           {
            column =  column + yyleng;
            error_morfologico();
            return TOK_ERROR;
            }

{SALTO}     {
            row=row+1;
            column=0;
            }


%%
