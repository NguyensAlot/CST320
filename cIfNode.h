/*****************************************************
 * Class: cIfNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: When if keyword is read, cIfNode is called
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

class cIfNode : public cStmtNode
{
public:
    cIfNode(cExprNode* expr, cStmtNode* stmt1 = nullptr, cStmtNode* stmt2 = nullptr)
    {
        _expr = expr;
        _stmt1 = stmt1;
        _stmt2 = stmt2;
    }
    string toString()
    {
        string strHolder = _expr->toString() + "\n" + _stmt1->toString() + "\n";
        
        if (_stmt2 != nullptr)
            strHolder += "ELSE:\n" + _stmt2->toString() + "\n";
        
        return "(IF: " + strHolder + ")";
    }
private:
    cExprNode* _expr;
    cStmtNode* _stmt1;
    cStmtNode* _stmt2;
};