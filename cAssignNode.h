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
        
        error = check();
        if (error)
            semantic_error("Cannot assign " + _expr->getType()->stringType() + " to " + _varRef->getType()->stringType());
    }
    string toString()
    {
        return "(ASSIGN: " + _varRef->toString() + " = " + _expr->toString() + ")";
    }
    
    bool check()
    {
        //error = false;
        // if nullptr, do nothing
        if (_varRef->getType() == nullptr || _expr->getType() == nullptr);
        else if (_varRef->getType() != _expr->getType())
        {
            // if both are structs
            if (_varRef->getType()->IsStruct() && _expr->getType()->IsStruct())
                // if structs are name different
                if (_varRef->getType()->stringType() != _expr->getType()->stringType())
                    //error = true;
                    return true;
            // anything non-struct can't be assigned to a struct
            if (_varRef->getType()->IsStruct() && !_expr->getType()->IsStruct())
                //error = true;
                return true;
            // right hand side can't be larger size than left hand side
            if (_varRef->getType()->getSize() < _expr->getType()->getSize())
                //error = true;
                return true;
        }
        //return error;
        return false;
    }
private:
    cVarRefExprNode* _varRef;
    cExprNode* _expr;
};