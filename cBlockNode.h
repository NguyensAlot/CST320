#pragma once
//*******************************************************
// Purpose: Class to represent a block
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Editor: Anthony Nguyen
// Email:  anthony.nguyen@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cStmtsNode.h"
#include "cDeclsNode.h"

// blocks can be statements (e.g. if (cond) {block}
class cBlockNode : public cStmtNode
{
  public:
    cBlockNode(cDeclsNode *decls, cStmtsNode *stmts) : cStmtNode()
    {
        mDecls = decls;
        mStmts = stmts;
    }

    virtual std::string toString()
    {
        std::string result("BLOCK: ");
        result += "size: " + std::to_string(mSize) + "\n{\n";
      
        if (mDecls != NULL) result += mDecls->toString();
        if (mStmts != NULL) result += mStmts->toString();
        
        result += "}\n";
        return result;
    }

  virtual int Computeoffsets(int base)
  {
        // create variable and set it to base
        int offset = base;
        
        // make calls to Computeoffsets to recursively return values
        if (mDecls != nullptr)
            offset = mDecls->Computeoffsets(offset);
        if (mStmts != nullptr)
            offset = mStmts->Computeoffsets(offset);
        
        // subtract base from offset to get size
        mSize = offset - base;
        
        // return base as offset
        return base;
  }
  
  void GenerateCode()
    {
        if(mDecls != nullptr)
        {
            mDecls->GenerateCode();
            EmitString("Stack_Pointer += " + std::to_string(mSize) + ";\n");
        }
        if(mStmts != nullptr)
            mStmts->GenerateCode();
        
        if (mDecls != nullptr)
            EmitString("Stack_Pointer -= " + std::to_string(mSize) + ";\n");
    
    }

  protected:
    cDeclsNode *mDecls;     // declarations
    cStmtsNode *mStmts;     // statements
    int mSize;
};

