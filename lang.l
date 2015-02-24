%{
// lang lexer definition file
//
// Author: Alexander Tappin, Anthony Nguyen
// Primary: Alexander Tappin
// alexander.tappin@oit.edu, anthony.nguyen@oit.edu

//#include "tokens.h"
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
float               [-]?[0-9]+\.[0-9]+
punctuation         [{}()\[\];,\.]
operators           =|"|"|[*\-+\/%]
comments            "//".*$
whitespace          [' '\t\n]*
%%
    // token definitions go here.
"array"                     RETURN(ARRAY);
"if"                        RETURN(IF);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN);
{comments}                  //no comments
{identifiers}               {  
                                yylval.symbol = symbolTableRoot->LookupSym(yytext);
                                
                                if(yylval.symbol != nullptr)
                                {
                                    if(yylval.symbol->getIsType())
                                       RETURN(TYPE_ID);
                                }
                                else
                                    yylval.symbol = new cSymbol(yytext);
                                RETURN(IDENTIFIER);
                            }
{integer}                   {
                                yylval.int_val = atoi(yytext);
                                RETURN(INT_VAL);
                            }
{float}                     {
                                yylval.float_val = atof(yytext);
                                RETURN(FLOAT_VAL);
                            }



{operators}                 RETURN(yytext[0]);
{punctuation}               RETURN(yytext[0]);
{whitespace}                //no whitespace
.                           RETURN(JUNK_TOKEN);
%%

    // This function allows us to do extra processing on each token
static int Return(int val)
{
    //printf("Scanned '%s': %d\n", yytext, val);
    return val;
}


