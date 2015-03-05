#pragma once
//*******************************************************
// Purpose: Base class for all declarations
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>
#include <list>
using std::list;

#include "cAstNode.h"
#include "cAstList.h"
#include "cDeclNode.h"

using std::list;

class cDeclsNode : public cAstNode
{
  public:
    // constructor places first decl in list
    cDeclsNode(cDeclNode *decl) : cAstNode()
    {
        mList = new list<cDeclNode *>();
        mList->push_back(decl);
    }

    // add a declaration to the list
    void AddNode(cDeclNode *decl) 
    {
        mList->push_back(decl);
    }

    virtual std::string toString()
    {
        std::string result("DECLS:\n{\n");
        result += ListToString<cDeclNode *>(mList, true);
        result += "}\n";

        return result;
    }
    
    virtual int Computeoffsets(int base)
    {
        // create variable and set it to base
        int offset = base;
      
        // iterate through the list of cDeclNodes to call Computeoffsets to recursively return values
        for(list<cDeclNode *>::iterator it = mList->begin(); it != mList->end(); it++)
            offset = (*it)->Computeoffsets(offset);
        
        // subtract base from offset to get size
        mSize = offset - base;
        
        // return the offset
        return offset;
    }

    int Size()
    {
        return mSize;
    }

  protected:
    list<cDeclNode *> *mList;       // list of delcarations
    int mSize;
};

