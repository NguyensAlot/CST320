#pragma once
#include "cAstNode.h"

using namespace std;

class printNode : public cAstNode
{
public:    
    int text;
    printNode(int val)
    {
        text = val;
    }

    virtual string toString()
    {
        return "PRINT: (EXPR: " + to_string(text) + ")";
    }
private:

};