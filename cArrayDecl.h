/*****************************************************
 * Class: cArraySpec
 * Author: Anthony Nguyen
 * Description: Takes care of arrays
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cArraySpec.h"
#include "cDeclNode.h"

class cArrayDecl : public cDeclNode
{
public:
    cArrayDecl(cSymbol* type, cSymbol* identifier, cArraySpec* val)
    {
        _type = type;
        _identifier = identifier;
        _val = val;
    }
    
    string toString()
    {
        return "ARRAY: " + _type->toString() + " " + _identifier->toString() + " " + _val->toString();
    }
    
    int getSize()
    {
        return 0;
    }
    
    string stringType()
    {
        return "array Decl";
    }
private:
    cSymbol* _type;
    cSymbol* _identifier;
    cArraySpec* _val;
};