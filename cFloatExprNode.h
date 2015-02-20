/*****************************************************
 * Class: cFloatExprNode.h
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of float values
 * **************************************************/
#pragma once
#include "cExprNode.h"

using namespace std;

class cFloatExprNode : public cExprNode
{
public:
    cFloatExprNode(double val)
    {
        float_val = val;
    }
    virtual string toString()
    {
        return "(EXPR: " + to_string(float_val) + ")";
    }
private:
    double float_val;
};