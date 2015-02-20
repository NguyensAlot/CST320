/*****************************************************
 * Class: cFuncHeader
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function header
 * **************************************************/
#pragma once
#include "cFuncPrefix.h"
#include "cParamsSpec.h"
 
using namespace std;

class cFuncHeader
{
public:
    cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params = nullptr)
    {
        _prefix = prefix;
        _params = params;
    }
    virtual string toString()
    {
        string strHolder = _prefix->toString();
        
        if (_params != nullptr)
            strHolder += " " + _params->toString();
        else
            strHolder += "()";
            
        return strHolder;
    }
private:
    cFuncPrefix* _prefix;
    cParamsSpec* _params;
};