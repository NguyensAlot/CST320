#pragma once
//*******************************************************
// Purpose: Class for a function definiiton or delcaration
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

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cExprNode.h"
#include "cParamsSpecNode.h"

class cFuncDeclNode : public cDeclNode
{
  public:
    // return type and name of function
    cFuncDeclNode(cSymbol *type, cSymbol *id)
    {
        cSymbol *existingSymbol = symbolTableRoot->LocalLookup(id->Name());
        if (existingSymbol != NULL && existingSymbol->GetType()->IsFunc())
        {
            // we already have a declaration, so make this one match
            cFuncDeclNode *fDecl = 
                dynamic_cast<cFuncDeclNode *>(existingSymbol->GetType());
            mId = existingSymbol;
            mReturnType = fDecl->mReturnType;
            mParams = fDecl->mParams;
            mDecls = fDecl->mDecls;
            mStmts = fDecl->mStmts;
            mParamsSet = fDecl->mParamsSet;
            mId->SetType(this);
        } else {
            symbolTableRoot->Insert(id);
            mReturnType = type;
            mId = id;
            mParams = NULL;
            mDecls = NULL;
            mStmts = NULL;
            mParamsSet = false;
            mId->SetType(this);
        }
    }

    // return the type of the return value
    virtual cDeclNode *GetBaseType()
    {
        return mReturnType->GetType();
    }

    virtual bool IsFunc()   { return true; }

    // size of the returned value
    virtual int ReturnSize(){ return mReturnType->GetType()->Size(); }

    // set the params. This can't be done in the constructor because
    // we create the node on the function header
    void SetParams(cParamsSpecNode *params)
    {
        if (!mParamsSet)
        {
            mParams = params;
            mParamsSet = true;
        }
    }

    // return the parameter list
    cParamsSpecNode *GetParams()
    { return mParams; }

    // set the local var delcs and the statments
    void SetBody(cDeclsNode *decls, cStmtsNode *stmts)
    {
        mDecls = decls;
        mStmts = stmts;
    }

    virtual std::string toString()
    {
        std::string result("(FUNC: ");
        result += mId->toString();
        if (mParams != NULL) 
            result += mParams->toString();
        else
            result += "()";
        if (mDecls != NULL) result += "\n" + mDecls->toString();
        if (mStmts != NULL) result += "\n" + mStmts->toString();
        result += "\nsize: " + std::to_string(mSize);
        result += "\n)";
        
        return result;
    }
    
    void GenerateCode()
    {
        EmitString("int ");
        EmitString(mId->Name());
        EmitString("( ");
        
        if(mParams != nullptr)
            mParams->GenerateCode();
        EmitString(" )\n{\n");
        
        if(mDecls != nullptr)
            mDecls->GenerateCode();
        
        if(mStmts != nullptr)
            mStmts->GenerateCode();
        
        EmitString("\n}\n");
    }
    
    virtual int Computeoffsets(int base)
    {
        // set offset to 0 because of its scope
        int offset = 0;
        
        // make calls to Computeoffsets to recursively return values
        if (mParams != nullptr)
            offset = mParams->Computeoffsets(offset);
        if (mDecls != nullptr)
            offset = mDecls->Computeoffsets(offset);
        if (mStmts != nullptr)
            offset = mStmts->Computeoffsets(offset);
        if (mDecls != nullptr)
            mSize = mDecls->Size();
        return base;
    }

  protected:
    cSymbol *mReturnType;       // return type of function
    cParamsSpecNode *mParams;   // formal parameter list
    cDeclsNode *mDecls;         // local variables
    cStmtsNode *mStmts;         // executable statements
    bool mParamsSet;            // indicates parameters have been set
    int mDeclsSize;             // size of the declarations. Needed to
                                // allocate space on the stack for locals
};

