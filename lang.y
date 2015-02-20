/* lang.y */

%{
#include <iostream>
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "cAstNode.h"
#include "lex.h"
%}

%locations

%union
    {
        int                 int_val;
        double              float_val;
        cSymbol*            symbol;
        cSymbolTable*       sym_table;
        cAstNode*           ast_node;
        cExprNode*          expr_node;
        cStmtNode*          stmt_node;
        cDeclNode*          decl_node;
        cBlockNode*         block_node;
        cPrintNode*         print_node;
        cStmtsNode*         stmts_node;
        cDeclsNode*         decls_node;
        cVarRefExprNode*    var_node;
        cVarPartNode*       var_p_node;
        cParamNode*         param_node;
        cParamsNode*        params_node;
        cParamSpec*         param_spec;
        cParamsSpec*        params_spec;
        cFuncCall*          func_call;
        cFuncHeader*        func_header;
        cFuncPrefix*        func_prefix;
        cArraySpec*         array_spec;
        cArrayVal*          array_val;
    }

%{
    int yyerror(const char *msg);
    
    cAstNode *yyast_root;
%}

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token  SCAN PRINT
%token  WHILE IF ELSE 
%token  STRUCT
%token  RETURN
%token  JUNK_TOKEN

%type <block_node> program
%type <block_node> block
%type <sym_table> open
%type <sym_table> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> func_decl
%type <func_header> func_header
%type <func_prefix>  func_prefix
%type <func_call> func_call
%type <params_spec> paramsspec
%type <param_spec> paramspec
%type <array_spec> arrayspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <var_node> lval
%type <array_val> arrayval
%type <params_node> params
%type <param_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact 
%type <var_node> varref
%type <var_p_node> varpart

%%

program: block                  { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close  {
                                    $$ = new cBlockNode($2, $3);
                                }
    |   open stmts close        {
                                    $$ = new cBlockNode(nullptr, $2);
                                }
open:   '{'                     {
                                    symbolTableRoot->IncreaseScope();
                                    $$ = NULL; //change this
                                }
close:  '}'                     {
                                    symbolTableRoot->DecreaseScope();
                                    $$ = NULL;
                                }
decls:      decls decl          {
                                    if($1 == nullptr)
                                        $1 = new cDeclsNode();
                                    $$ = $1;
                                    $$->addNode($2);
                                }
        |   decl                {
                                    
                                    $$ = new cDeclsNode();
                                    $$->addNode($1);
                                }
decl:       var_decl ';'        {
                                    $$ = $1;
                                }
        |   struct_decl ';'     {
                                    $$ = $1;
                                }
        |   func_decl           {
                                    $$ = $1;
                                }
        |   error ';'           {}
var_decl:   TYPE_ID IDENTIFIER arrayspec    
                                {
                                    $2 = symbolTableRoot->Insert($2->getmSymbol()); 
                                    $$ = new cVarDeclNode($1, $2, $3);
                                }
        |   struct_decl IDENTIFIER arrayspec
                                {}
struct_decl:  STRUCT open decls close IDENTIFIER    
                                {
                                    $5->setTypeTrue();
                                    $$ = new cStructDeclNode($2, $3, $5);    
                                }
func_decl:  func_header ';'
                                {
                                    $$ = new cFuncDeclNode($1);
                                    symbolTableRoot->DecreaseScope();
                                }
        |   func_header  '{' decls stmts '}'
                                {
                                    $$ = new cFuncDeclNode($1, $3, $4);
                                    symbolTableRoot->DecreaseScope();
                                }
        |   func_header  '{' stmts '}'
                                {
                                    $$ = new cFuncDeclNode($1, nullptr, $3);
                                    symbolTableRoot->DecreaseScope();
                                }
func_header: func_prefix paramsspec ')'
                                {
                                    $$ = new cFuncHeader($1, $2);
                                }
        |    func_prefix ')'    {
                                    $$ = new cFuncHeader($1);
                                }
func_prefix: TYPE_ID IDENTIFIER '('
                                {
                                    symbolTableRoot->IncreaseScope();
                                    $$ = new cFuncPrefix($1, $2);
                                }
paramsspec:     
            paramsspec',' paramspec 
                                {
                                    if ($1 == nullptr)
                                        $1 = new cParamsSpec();
                                    $$ = $1;
                                    $$->addNode($3);
                                }
        |   paramspec           {
                                    $$ = new cParamsSpec();
                                    $$->addNode($1);
                                }

paramspec:  var_decl            {
                                    $$ = new cParamSpec((cVarDeclNode*)$1);
                                }

arrayspec:  arrayspec '[' INT_VAL ']'
                                {
                                    if ($1 == nullptr)
                                        $1 = new cArraySpec();
                                    $$ = $1;
                                    $$->addNode($3);
                                }
        |   /* empty */         {
                                    $$ = NULL;
                                }

stmts:      stmts stmt          {
                                    if($1 == nullptr)
                                        $1 = new cStmtsNode();
                                    $$ = $1;
                                    $$->addNode($2);
                                }
        |   stmt                {
                                    $$ = new cStmtsNode();
                                    $$->addNode($1);
                                }

stmt:       IF '(' expr ')' stmt 
                                {
                                    $$ = new cIfNode($3, $5);
                                }
        |   IF '(' expr ')' stmt ELSE stmt
                                {
                                    $$ = new cIfNode($3, $5, $7);
                                }
        |   WHILE '(' expr ')' stmt
                                {
                                    $$ = new cWhileNode($3, $5);
                                }
        |   PRINT '(' expr ')' ';'
                                {
                                    $$ = new cPrintNode($3);
                                }
        |   SCAN '(' lval ')' ';'
                                {
                                    $$ = new cScanNode($3);
                                }
        |   lval '=' expr ';'   {
                                    $$ = new cAssignNode($1, $3);
                                }
        |   func_call ';'       {}
        |   block               {}
        |   RETURN expr ';'     {
                                    $$ = new cReturnNode($2);
                                }
        |   error ';'           {}

func_call:  IDENTIFIER '(' params ')' 
                                {
                                    $$ = new cFuncCall($1, $3);
                                }
varref:   varref '.' varpart    {
                                    $$ = $1;
                                    $$->addNode($3);
                                }
        | varpart               {
                                    $$ = new cVarRefExprNode();
                                    $$->addNode($1);
                                    
                                }

varpart:  IDENTIFIER arrayval   {
                                    $$ = new cVarPartNode($1, $2);
                                }

lval:     varref                {
                                    $$ = $1;
                                }
arrayval: arrayval '[' expr ']' {
                                    if ($1 == nullptr)
                                        $1 = new cArrayVal();
                                    $$ = $1;
                                    $$->addNode($3);
                                }
        |   /* empty */         {
                                    $$ = NULL;
                                }

params:     params ',' param    {
                                    if ($1 == nullptr)
                                        $1 = new cParamsNode();
                                    $$ = $1;
                                    $$->addNode($3);
                                }
        |   param               {
                                    $$ = new cParamsNode();
                                    $$->addNode($1);
                                }

param:      expr                {
                                    $$ = new cParamNode($1);
                                }
        |   /* empty */         {
                                    $$ = NULL;
                                }

expr:       expr '+' term       {
                                    $$ = new cBinaryExprNode($1, '+', $3);    
                                }
        |   expr '-' term       {
                                    $$ = new cBinaryExprNode($1, '-', $3);
                                }
        |   term                {
                                    $$ = $1;
                                }

term:       term '*' fact       {
                                    $$ = new cBinaryExprNode($1, '*', $3);
                                }
        |   term '/' fact       {
                                    $$ = new cBinaryExprNode($1, '/', $3);
                                }
        |   term '%' fact       {
                                    $$ = new cBinaryExprNode($1, '%', $3);
                                }
        |   fact                {
                                    $$ = $1;
                                }

fact:        '(' expr ')'       {
                                    $$ = $2;
                                }
        |   INT_VAL             {
                                    $$ = new cIntExprNode($1);
                                }
        |   FLOAT_VAL           {
                                    $$ = new cFloatExprNode($1);
                                }
        |   varref              {
                                    $$ = $1;
                                }
        |   func_call           {
                                    //$$ = $1;
                                }

%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
