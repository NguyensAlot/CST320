#pragma once
//*******************************************************
// Purpose: A list of actual params passed to a function
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>
#include <list>

#include "cAstNode.h"
#include "cExprNode.h"
#include "cAstList.h"

using std::list;

class cParamNode: public cAstNode
{
  public:
    // place the first param in the list
    cParamNode(cExprNode *param) : cAstNode()
    {
        mList = new list<cExprNode *>();
        if (param != NULL) mList->push_back(param);
    }

    // place the next param in the list
    void AddNode(cExprNode *param) 
    {
        mList->push_back(param);
    }

    // return a specific param
    cExprNode *GetParam(int index)
    {
        return ListGetItem(mList, index);
    }

    int NumParams()
    { return mList->size(); }

    virtual std::string toString()
    {
        std::string result("(PARAM:");
        result += ListToString(mList, false);
        result += ")\n";

        return result;
    }
    
    virtual int Computeoffsets(int base)
    {
        // iterate through the list of cDeclNodes to call Computeoffsets to recursively return values
        for(list<cExprNode *>::iterator it = mList->begin(); it != mList->end(); it++)
            (*it)->Computeoffsets(base);
        
        return base;
    }

  protected:
    list<cExprNode *> *mList;       // list of parameters
};

