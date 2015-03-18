#pragma once
//*******************************************************
// Purpose: list of formal params to a function
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
#include <list>
using std::list;

#include "cAstNode.h"
#include "cAstList.h"
#include "cVarDeclNode.h"

class cParamsSpecNode: public cAstNode
{
  public:
    // place the first param in the list
    cParamsSpecNode(cVarDeclNode *param) : cAstNode()
    {
        mList = new list<cVarDeclNode *>();
        mList->push_back(param);
    }

    // Add another param to the list
    void AddNode(cVarDeclNode *param) 
    {
        mList->push_back(param);
    }

    // return the number of params
    int NumParams()
    { return mList->size(); }

    // return a specific param
    cVarDeclNode *GetParam(int index)
    {
        return ListGetItem(mList, index);
    }

    virtual std::string toString()
    {
        std::string result("(PARAMS:");
        result += ListToString(mList, false);
        result += ")\n";

        return result;
    }
    
    virtual int Computeoffsets(int base)
    {
        int offset = base;
      
      // iterate through the list of cDeclNodes to call Computeoffsets to recursively return values
        for(list<cVarDeclNode *>::iterator it = mList->begin(); it != mList->end(); it++)
            offset = (*it)->Computeoffsets(offset);
        
        return offset;
    }
  protected:
    list<cVarDeclNode *> *mList;    // list of formal params
};

