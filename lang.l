%{
// lang lexer definition file
//
// Author: Anthony Nguyen anthony.nguyen@oit.edu

#include "tokens.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */

punctuation     [(){}\[\];,\.]
operators       [+\-*/%<!=]
string          [a-zA-Z][a-zA-Z0-9_]*
integer         -?[0-9]+
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
"int"                       RETURN(INT);
"float"                     RETURN(FLOAT);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN_TOK);
"char"                      RETURN(CHAR);
"end"                       RETURN(END);
{punctuation}               RETURN(yytext[0]);
{operators}                 RETURN(yytext[0]);
{string}                    RETURN(IDENTIFIER);
{integer}                   RETURN(INT_VAL);
{float}                     RETURN(FLOAT_VAL);
{whitespace}                {};
{comment}                   {};
{junk}                      RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

