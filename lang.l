%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu

#include "tokens.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */
comment         "//".+$
junk            [:@#\$]
period          ['.']
integer         [0-9]+
float           [0-9]+.[0-9]+
operators       ==|&&|\|\||[+\-*/%=]
punctuation     [.(){}[\];,\.]
string          [a-zA-Z]+
whitespace      [\t\r\n\v\f]

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
{integer}                   RETURN(INT_VAL);
{float}                     RETURN(FLOAT_VAL);
{operators}                 RETURN(OPERATOR);
{punctuation}               RETURN(yytext[0]);
{junk}                      RETURN(JUNK_TOKEN);
{comment}                   {};
{string}                    RETURN(IDENTIFIER);
{whitespace}                {};


%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

