/*****************************************************
 * Class: cParamNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of parameters
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cExprNode.h"

class cParamNode : public cAstNode
{
public:
    cParamNode(cExprNode* expr)
    {
        _expr = expr;
    }
    string toString()
    {
        return _expr->toString();
    }
private:
    cExprNode* _expr;
};