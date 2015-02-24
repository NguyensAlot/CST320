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
        {
            semantic_error("Cannot assign " + _expr->getType()->stringType() + " to " + _varRef->getType()->stringType());
            error = false;
        }
    }
    string toString()
    {
        return "(ASSIGN: " + _varRef->toString() + " = " + _expr->toString() + ")";
    }
    
    bool check()
    {
        //if (_varRef->getType() == nullptr || _expr->getType() == nullptr);
        if (_varRef->getType() != _expr->getType())
        {
            // char accepts nothing, but itself
            if(_varRef->getType()->IsChar())
                return true;
            // int doesnt accept float or struct
            if(_varRef->getType()->IsInt() && (_expr->getType()->IsFloat() || _expr->getType()->IsStruct()))
                return true;
            // float doesnt accept a struct
            if(_varRef->getType()->IsFloat() && _expr->getType()->IsStruct())
                return true;
            // struct does not accept anything else
            if(_varRef->getType()->IsStruct() && (_expr->getType()->IsInt() || _expr->getType()->IsFloat() || _expr->getType()->IsChar()))
                return true;
            // both are structs, but different names
            if(_varRef->getType()->IsStruct() && _expr->getType()->IsStruct())
                if(_varRef->getType()->stringType() != _expr->getType()->stringType())
                    return true;
            // Only one of the two are arrays
            if((!_varRef->getType()->IsArray() && _expr->getType()->IsArray()) || (_varRef->getType()->IsArray() && !_expr->getType()->IsArray()))
                return true;
            // both are arrays, but different names
            if((_varRef->getType()->IsArray() && _expr->getType()->IsArray()) && (_varRef->getType()->stringType() != _expr->getType()->stringType()))
                return true;
        }
        return false;
    }
private:
    cVarRefExprNode* _varRef;
    cExprNode* _expr;
};