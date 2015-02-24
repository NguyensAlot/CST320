/*****************************************************
 * Class: cArraySpec
 * Author: Anthony Nguyen
 * 
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
    
    bool IsArray()
    {
        return true;
    }
    
    cDeclNode* getBaseType()
    {
        return _type->getType();
    }
    
    cDeclNode* getType()
    {
        return _identifier->getType();
    }
    
    int getSize()
    {
        return -10;
    }
    
    string stringType()
    {
        return _identifier->getmSymbol();
    }
private:
    cSymbol* _type;
    cSymbol* _identifier;
    cArraySpec* _val;
};