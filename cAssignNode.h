/*****************************************************
 * Class: cAssignNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable assignment. 
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cDeclNode.h"
#include "cExprNode.h"
#include "cVarRefExprNode.h"

extern cSymbolTable* symbolTableRoot;

class cAssignNode : public cStmtNode
{
public:
    cAssignNode(cVarRefExprNode* varRef, cExprNode* expr)
    {
        _varRef = varRef;
        _expr = expr;
    }
    string toString()
    {
        return "(ASSIGN: " + _varRef->toString() + " = " + _expr->toString() + ")";
    }
    
    bool SemanticError()
    {
        error = true;
        if(_varRef->getType() != _expr->getType())
        {
            //Do this
            if(_varRef->getType()->getSize() < _expr->getType()->getSize())
            {
                error = false;
            }
        }
        return error;
    }
private:
    cVarRefExprNode* _varRef;
    cExprNode* _expr;
};