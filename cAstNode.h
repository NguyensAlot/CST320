#pragma once
//*******************************************************
// Purpose: Base class for all AST nodes
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <iostream>
#include "codegen.h"
#include <string>

class cAstNode
{
  public:
    cAstNode() {mSemanticError = false;}

    // return a string representation of the class
    virtual std::string toString() = 0;

    // return true if a semantic error was detected in this node
    virtual bool SemanticError() { return mSemanticError; }
    
    // compute the offset for each variable and return offset
    virtual int Computeoffsets(int base) { return base; }
    
    virtual void GenerateCode()
    {
    }

  protected:
    bool mSemanticError;        // true indicates this node has a semantic error
    int mBase;                  // offset of variable
};

