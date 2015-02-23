/*****************************************************
 * Class: cFloatExprNode.h
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of float values
 * **************************************************/
#pragma once
#include "cExprNode.h"

extern cSymbolTable* symbolTableRoot;

using namespace std;

class cFloatExprNode : public cExprNode
{
public:
    cFloatExprNode(double val)
    {
        float_val = val;
    }
    
    string toString()
    {
        return "(EXPR: " + to_string(float_val) + ")";
    }
    
    cDeclNode* getType()
    {
        return symbolTableRoot->LookupSym("float")->getType();
    }
private:
    double float_val;
};