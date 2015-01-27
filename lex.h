#pragma once
//**************************************
// lex.h
//
// Defines global symbols used the the flex generated lexer and 
// bison generated parser.
//
// Author: Anthony Nguyen   anthony.nguyen@oit.edu
//

#include "cSymbolTable.h"
#include "cSymbol.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();