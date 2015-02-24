/*****************************************************
 * Class: cParamsNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of parameters
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cParamNode.h"

class cParamsNode : public cStmtNode
{
public:
    cParamsNode() {}
    
    string toString()
    {
        string strHolder;
        
        for(list<cParamNode*>::iterator it = _paramList.begin(); it != _paramList.end(); it++)
            strHolder += (*it)->toString();
            
        return "(PARAM:" + strHolder + ")\n";
    }
    
    void addNode(cParamNode* param)
    {
        // add to the back of the list
        _paramList.push_back(param);
    }
    
private:
    list<cParamNode*> _paramList;
};