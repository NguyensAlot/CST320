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
    
    string toString()
    {
        return "(EXPR: " + _expr1->toString() + " " + _op + " " + _expr2->toString() + ")";
    }
    
    cDeclNode* getType()
    {
        if (_expr1->getType() == _expr2->getType() || _expr1->getType()->IsFloat())
            return _expr1->getType();
        else if (_expr2->getType()->IsFloat())
            return _expr2->getType();
        else 
            return _expr2->getType();
    }
private:
    cExprNode* _expr1;
    char _op;
    cExprNode* _expr2;
};