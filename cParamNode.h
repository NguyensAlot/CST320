/*****************************************************
 * Class: cParamNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of parameters
 * **************************************************/
#pragma once
#include "cExprNode.h"

class cParamNode
{
public:
    cParamNode(cExprNode* expr)
    {
        _expr = expr;
    }
    virtual string toString()
    {
        return _expr->toString();
    }
private:
    cExprNode* _expr;
};