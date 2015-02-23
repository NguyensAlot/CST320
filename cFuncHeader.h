/*****************************************************
 * Class: cFuncHeader
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function header
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cFuncPrefix.h"
#include "cParamsSpec.h"
 
using namespace std;

class cFuncHeader : public cAstNode
{
public:
    cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params = nullptr)
    {
        _prefix = prefix;
        _params = params;
    }
    string toString()
    {
        string strHolder = _prefix->toString();
        
        if (_params != nullptr)
            strHolder += " " + _params->toString();
        else
            strHolder += "()";
            
        return strHolder;
    }
    
    cSymbol* getTypeSymbol()
    {
        return _prefix->getTypeSymbol();
    }
    
private:
    cFuncPrefix* _prefix;
    cParamsSpec* _params;
};