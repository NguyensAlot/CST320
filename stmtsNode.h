#pragma once
#include "cAstNode.h"

using namespace std;

class stmtsNode : public cAstNode
{
public:
    stmtsNode(cAstNode* val)
    {
        text = val;
    }
    virtual string toString()
    {
        return "STMTS:\n{" + text->toString() + "\n}\n";
    }
private:
    cAstNode* text;
};