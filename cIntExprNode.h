/*****************************************************
 * Class: cIntExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Called when an integer value is read.
 * **************************************************/
#pragma once
#include "cExprNode.h"

extern cSymbolTable* symbolTableRoot;

using namespace std;

class cIntExprNode : public cExprNode
{
public:
    cIntExprNode(int val)
    {
        integer_val = val;
    }
    
    string toString()
    {
        return "(EXPR: " + to_string(integer_val) + ")";
    }
    
    cDeclNode* getType()
    {
        if (integer_val >= -128 && integer_val <= 127)
            return symbolTableRoot->LookupSym("char")->getType();
        return symbolTableRoot->LookupSym("int")->getType();
    }
private:
    int integer_val;
};