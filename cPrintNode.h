#pragma once
//*******************************************************
// Purpose: Class for a print statement
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cExprNode.h"

class cPrintNode : public cStmtNode
{
  public:
    cPrintNode(cExprNode *expr) : cStmtNode()
    {
        mExpr = expr;
    }

    virtual std::string toString()
    {
        std::string result("PRINT: ");
        result += mExpr->toString();
        return result;
    }

    virtual int Computeoffsets(int base)
    {
        // make calls to Computeoffsets to recursively return values
        mExpr->Computeoffsets(base);
        return base;
    }

  protected:
    cExprNode *mExpr;       // expression to be printed
};

