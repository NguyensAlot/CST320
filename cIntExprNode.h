/*****************************************************
 * Class: cIntExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Called when an integer value is read.
 * **************************************************/
#pragma once
#include "cExprNode.h"

using namespace std;

class cIntExprNode : public cExprNode
{
public:
    cIntExprNode(int val)
    {
        integer_val = val;
    }
    virtual string toString()
    {
        return "(EXPR: " + to_string(integer_val) + ")";
    }
private:
    int integer_val;
};