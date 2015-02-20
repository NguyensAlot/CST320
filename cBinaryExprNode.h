/*****************************************************
 * Class: cBinaryExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of binary expressions
 * **************************************************/
#pragma once
#include "cExprNode.h"

using namespace std;

class cBinaryExprNode : public cExprNode
{
public:
    cBinaryExprNode(cExprNode* expr1, char op, cExprNode* expr2) 
    {
        _expr1 = expr1;
        _op = op;
        _expr2 = expr2;
    }
    virtual string toString()
    {
        return "(EXPR: " + _expr1->toString() + " " + _op + " " + _expr2->toString() + ")";
    }
private:
    cExprNode* _expr1;
    char _op;
    cExprNode* _expr2;
};