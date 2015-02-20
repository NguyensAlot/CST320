/*****************************************************
 * Class: cWhileNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of while statements
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

class cWhileNode: public cStmtNode
{
public:
    cWhileNode(cExprNode* expr, cStmtNode* stmt)
    {
        _expr = expr;
        _stmt = stmt;
    }
    string toString()
    {
        return "(WHILE: " + _expr->toString() + "\n" + _stmt->toString() + "\n)";
    }
    
private:
    cExprNode* _expr;
    cStmtNode* _stmt;
};