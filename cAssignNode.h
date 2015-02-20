/*****************************************************
 * Class: cAssignNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable assignment. 
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"
#include "cVarRefExprNode.h"

class cAssignNode : public cStmtNode
{
public:
    cAssignNode(cVarRefExprNode* varRef, cExprNode* expr)
    {
        _varRef = varRef;
        _expr = expr;
    }
    virtual string toString()
    {
        return "(ASSIGN: " + _varRef->toString() + " = " + _expr->toString() + ")";
    }
private:
    cVarRefExprNode* _varRef;
    cExprNode* _expr;
};