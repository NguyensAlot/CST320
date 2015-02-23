/*****************************************************
 * Class: cParamsSpec
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of parameter specs
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cParamSpec.h"
 
class cParamsSpec : public cStmtNode
{
public:
    cParamsSpec() {}
    string toString()
    {
        string strHolder;
        
        // iterate through list
        for  (list<cParamSpec*>::iterator it = _paramList.begin(); it != _paramList.end(); it++)
            strHolder += (" " + (*it)->toString());

        return "(PARAMS:" + strHolder + ")\n";
    }
    void addNode(cParamSpec* param)
    {
        // add to the back of the list
        _paramList.push_back(param);
    }
private:
    list<cParamSpec*> _paramList;
};