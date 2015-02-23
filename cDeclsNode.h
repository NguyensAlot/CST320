/*****************************************************
 * Class: cDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of declarations
 * **************************************************/
#pragma once
#include "cDeclNode.h"

using namespace std;

class cDeclsNode : public cAstNode
{
public:
    cDeclsNode() {}
    string toString()
    {
        string strHolder;
        
        for (list<cDeclNode*>::iterator it = _declList.begin(); it != _declList.end(); it++)
            strHolder += (*it)->toString() + "\n";
            
        return "DECLS:\n{\n" + strHolder + "}\n";
    }
    void addNode(cDeclNode* decl)
    {
        // add to the back of the list
        _declList.push_back(decl);
    }
private:
    list<cDeclNode*> _declList;
};