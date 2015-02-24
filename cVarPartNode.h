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
#include "cArrayDecl.h"

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
    
    bool isIndex()
    {
        if (_array == nullptr)
            return false; 
        return true;
    }
    
    cDeclNode* getType()
    {
        if (isIndex())
            return dynamic_cast<cArrayDecl*>(_var->getType())->getBaseType();
        else
            return _var->getType();
    }
    
    void setSym(cSymbol* var)
    {
        _var = var;
    }
    
    cSymbol* getSym()
    {
        return _var;
    }
    
private:
    cSymbol* _var;
    cArrayVal* _array;
};