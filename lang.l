%{
// lang lexer definition file
//
// Author: Anthony Nguyen anthony.nguyen@oit.edu
//
// Illustration showing how to use {} to control scope

#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "langparse.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */

identifiers         [a-zA-Z][a-zA-Z0-9_]*
integer             [-]?[0-9]+
float               [-]?[0-9]+.[0-9]+
punctuation         [{}()\[\];,.]
operators           =|"|"|[*\-+\/%]
comments            "//".*$
whitespace          [' '\t\n]*
%%
    // token definitions go here. "if" is an example.
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"struct"                    RETURN(STRUCT);
{comments}                  //no comments
{identifiers}               {  
                                yylval.symbol = symbolTableRoot->Insert(yytext);
                                return (IDENTIFIER);
                            }
{integer}                   RETURN(INT_VAL);
{float}                     RETURN(FLOAT_VAL);
{operators}                 RETURN(yytext[0]);
{punctuation}               RETURN(yytext[0]);
{whitespace}                //no whitespace
.                           RETURN(JUNK_TOKEN);
%%

    // This function allows us to do extra processing on each token
static int Return(int val)
{
    //    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

