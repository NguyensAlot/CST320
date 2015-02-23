/*****************************************************
 * Class: cVarDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable declarations
 * **************************************************/
#pragma once
#include "cDeclNode.h"
#include "cSymbol.h"

using namespace std;

class cVarDeclNode : public cDeclNode
{
public:
    cVarDeclNode(cSymbol* type, cSymbol* identifier)
    {
        _type = type;
        _identifier = identifier;
    }   
    string toString()
    {
        return "VAR: " + _type->toString() + " " + _identifier->toString();
    }
    
    cDeclNode* getType()
    {
        return _type->getType();
    }
    
    int getSize()
    {
        return _type->getType()->getSize();
    }
    
    string stringType()
    {
        return _type->getType()->stringType();
    }
    
private:
    cSymbol* _type;
    cSymbol* _identifier;
};