/*****************************************************
 * Class: cPrintNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of printing
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

using namespace std;

class cPrintNode : public cStmtNode
{
public:    
    cPrintNode(cExprNode* expr)
    {
        _expr = expr;
    }
    virtual string toString()
    {
        return "PRINT: " + _expr->toString();
    }
private:
    cExprNode* _expr;
};