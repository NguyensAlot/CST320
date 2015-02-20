/*****************************************************
 * Class: cBlockNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of blocks
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cStmtNode.h"

using namespace std;

class cBlockNode : public cAstNode
{
public:
    cBlockNode(cDeclsNode* decl = nullptr, cStmtsNode* stmt = nullptr)
    {
        _decl = decl;
        _stmt = stmt;
    }
    virtual string toString() 
    {
        string strHolder;
        
        if (_decl != nullptr)
            strHolder += _decl->toString();
        if (_stmt != nullptr)
            strHolder += _stmt->toString();
        
        return "BLOCK: \n{\n" + strHolder + "}\n";
    }
private:
    cDeclsNode* _decl;
    cStmtsNode* _stmt;
};