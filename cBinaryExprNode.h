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
        // if equal type return either
        if (_expr1->getType() == _expr2->getType())
            return _expr1->getType();
            
        // if either are float, return float
        else if (_expr1->getType()->IsFloat() || _expr2->getType()->IsFloat())
            return symbolTableRoot->LookupSym("float")->getType();
            
        // if LHS is greater, return it
        else if (_expr1->getType()->getSize() > _expr2->getType()->getSize())
            return _expr1->getType();
        
        // return largest
        else
            return _expr2->getType();
    }
private:
    cExprNode* _expr1;
    char _op;
    cExprNode* _expr2;
};