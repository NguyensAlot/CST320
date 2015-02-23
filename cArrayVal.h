/*****************************************************
 * Class: cArrayVal
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of arrays
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cExprNode.h"

using namespace std;

class cArrayVal : public cAstNode
{
public:
    cArrayVal() {}
    string toString()
    {
        string strHolder;
        
        // iterate through list
        for  (list<cExprNode*>::iterator it = _exprList.begin(); it != _exprList.end(); it++)
        {
            strHolder += (*it)->toString();
            
            // add 'space' if more than one item and not the last item
            if (_exprList.size() > 1 && (*it) != _exprList.back())
                strHolder += " ";
        }
            
        return "(ARRAYVAL:" + strHolder + ")";
    }
    void addNode(cExprNode* expr)
    {
        _exprList.push_back(expr);    
    }
private:
    list<cExprNode*> _exprList;
};