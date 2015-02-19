#pragma once
#include "cAstNode.h"

using namespace std;

class blockNode : public cAstNode
{
public:
    blockNode(cAstNode* val)
    {
        text = val;
    }
    virtual string toString() 
    {
        return "BLOCK: \n{\nSTMTS:\n{\n" + text->toString() + "\n}\n}\n";
    }
private:
    cAstNode* text;
};