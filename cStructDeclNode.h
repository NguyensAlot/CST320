/*****************************************************
 * Class: cStructDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of struct declaration
 * **************************************************/
#pragma once
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"

using namespace std;

class cStructDeclNode : public cDeclNode
{
    public:
        cStructDeclNode(cSymbolTable* symTable, cDeclsNode* decls, cSymbol* identifier)
        {
            _symTable = symTable;
            _decls = decls;
            _identifier = identifier;
        }
        string toString()
        {
            string returnValue;
            returnValue += _decls->toString() + " " + _identifier->toString();
            
            return "STRUCT: " + returnValue;
        }
    
    private:
        cSymbolTable* _symTable;
        cDeclsNode* _decls;
        cSymbol* _identifier;
        
};