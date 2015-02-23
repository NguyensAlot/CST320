/*****************************************************
 * Class: cVarPartNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of array variables
 * **************************************************/
#pragma once
#include "cExprNode.h"
#include "cSymbol.h"
#include "cArrayVal.h"

using namespace std;

class cVarPartNode : public cExprNode
{
public:
    cVarPartNode(cSymbol* var, cArrayVal* val = nullptr)
    {
        _var = var;
        _array = val;
    }
    
    string toString()
    {
        string strHolder = _var->toString();
        
        if(_array != nullptr)
            strHolder += "[" + _array->toString() + "]";
        
        return strHolder;
    }
    
    cDeclNode* getType()
    {
        return _var->getType();
    }
private:
    cSymbol* _var;
    cArrayVal* _array;
};