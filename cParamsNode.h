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
        
        // while list not empty
        while (!_paramList.empty())
        {
            // concatenate item on list to temp string, then pop from front
            strHolder += _paramList.front()->toString();
            _paramList.pop_front();
        }
        // if no list
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