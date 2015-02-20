/*****************************************************
 * Class: cVarRefExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable referencing
 * **************************************************/
#pragma once
#include "cExprNode.h"
#include "cVarPartNode.h"

using namespace std;

class cVarRefExprNode : public cExprNode
{
public:
    cVarRefExprNode() {}
    virtual string toString()
    {
        string strHolder;
        
        // create an iterator to iterate through list
        for  (list<cVarPartNode*>::iterator it = _varList.begin(); it != _varList.end(); it++)
        {
            strHolder += "(VarRef: " + (*it)->toString();
            
            if (_varList.size() > 1)
            {
                // if first item
                if (it == _varList.begin())
                    strHolder += "\n";
                // if not beginning or end    
                else if (it != _varList.begin() && (*it) != _varList.back())
                    strHolder += ")\n";
                // end
                else
                    strHolder += ")";
            }
        }
        
        return strHolder + ")";
    }
    void addNode(cVarPartNode* var)
    {
        // add to the back of the list
        _varList.push_back(var);
    }
private:
    list<cVarPartNode*> _varList;
};