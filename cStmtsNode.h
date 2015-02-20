/*****************************************************
 * Class: cStmtsNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of statements
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cStmtNode.h"

using namespace std;

class cStmtsNode : public cAstNode
{
public:
    cStmtsNode() {}
    virtual string toString()
    {
        string strHolder;
        
        // iterate through list
        for  (list<cStmtNode*>::iterator it = _stmtList.begin(); it != _stmtList.end(); it++)
             strHolder += (*it)->toString() + "\n";

        return "STMTS:\n{\n" + strHolder + "}\n";
    }
    void addNode(cStmtNode* stmt)
    {
        _stmtList.push_back(stmt);
    }
private:
    list<cStmtNode*> _stmtList;
};