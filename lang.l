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

operators       [+\-*/%<!=]
identifier      [a-zA-Z][a-zA-Z0-9_]*
integer         -?[0-9]+
punctuation     [{}()\[\];,.]
float           -?[0-9]+[\.][0-9]+
whitespace      [' '\t\n]+
comment         "//".*$
junk            .

%%

    // token definitions go here. "if" is an example.

"if"                        RETURN(IF);
"then"                      RETURN(THEN);
"else"                      RETURN(ELSE);
"for"                       RETURN(FOR);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"int"                       RETURN(INT_VAL);
"float"                     RETURN(FLOAT);
"struct"                    RETURN(STRUCT);
{comment}                   //no comments
{integer}                   RETURN(INT_VAL);
{float}                     RETURN(FLOAT_VAL);
{operators}                 RETURN(yytext[0]);
{punctuation}               RETURN(yytext[0]);
{identifier}                {  
                                yylval.symbol = symbolTableRoot->Insert(yytext);
                                return (IDENTIFIER);
                            }
{whitespace}                //no whitespace
.                           RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

