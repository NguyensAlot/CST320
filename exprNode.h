#pragma once
#include "cAstNode.h"

using namespace std;

class exprNode : public cAstNode
{
public:
    exprNode(int val)
    {
        text = val;
    }
    virtual string toString()
    {
        return "(EXPR: " + to_string(text) + ")";
    }
private:
    int text;
};