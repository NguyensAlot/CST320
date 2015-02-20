/*****************************************************
 * Class: cParamSpec
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function header
 * **************************************************/
#pragma once
#include "cVarDeclNode.h"

using namespace std; 

class cParamSpec
{
public:
    cParamSpec(cVarDeclNode* var)
    {
        _var = var;
    }
    virtual string toString()
    {
        return _var->toString();
    }
private:
    cVarDeclNode* _var;
};