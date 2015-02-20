/*****************************************************
 * Class: cVarDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable declarations
 * **************************************************/
#pragma once
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cArraySpec.h"

using namespace std;

class cVarDeclNode : public cDeclNode
{
public:
    cVarDeclNode(cSymbol* type, cSymbol* identifier, cArraySpec* val = nullptr)
    {
        _type = type;
        _identifier = identifier;
        _val = val;
    }   
    virtual string toString()
    {
        string strHolder = _type->toString() + " " + _identifier->toString();
        
        if (_val != nullptr)
            strHolder += " " + _val->toString();
        
        return "VAR: " + strHolder;
    }
private:
    cSymbol* _type;
    cSymbol* _identifier;
    cArraySpec* _val;
};