/*****************************************************
 * Class: cReturnNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: When a return is read, cReturnNode is called
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode: public cStmtNode
{
public:
    cReturnNode(cExprNode* expr)
    {
        _expr = expr;
    }
    string toString()
    {
        return "RETURN: " + _expr->toString();
    }
private:
    cExprNode* _expr;
};