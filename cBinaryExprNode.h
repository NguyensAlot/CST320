#pragma once
//*******************************************************
// Purpose: Class for binary expressions
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cExprNode.h"

class cBinaryExprNode : public cExprNode
{
  public:
    cBinaryExprNode(cExprNode *left, char op, cExprNode *right) : cExprNode()
    {
        mLeftExpr = left;
        mOperator[0] = op;
        mOperator[1] = '\0';
        mRightExpr = right;
    }

    // determine type based on types of operands
    // Normal promotion rules apply
    virtual cDeclNode *GetType()
    {
        cDeclNode *leftType  = mLeftExpr->GetType();
        cDeclNode *rightType = mRightExpr->GetType();
        cDeclNode *floatType = symbolTableRoot->Lookup("float")->GetType();
        cDeclNode *intType   = symbolTableRoot->Lookup("int")->GetType();

        if (leftType == rightType) return leftType;
        if (leftType->IsFloat() || rightType->IsFloat()) return floatType;
        return intType;
    }

    virtual std::string toString()
    {
        std::string result("(EXPR: ");
        result += mLeftExpr->toString() + " " + mOperator + " " + mRightExpr->toString();
        result += ")";

        return result;
    }

    void GenerateCode()
    {
        mLeftExpr->GenerateCode();
        EmitString(mOperator);
        mRightExpr->GenerateCode();
    }
    
    virtual int Computeoffsets(int base)
    {
        // make calls to Computeoffsets to recursively return values
        mLeftExpr->Computeoffsets(base);
        mRightExpr->Computeoffsets(base);
        
        return base;
    }
    
  protected:
    cExprNode *mLeftExpr;       // left expression
    cExprNode *mRightExpr;      // right expression
    char mOperator [2];             // operator: '+', '-', '*', '/', '%'
};

