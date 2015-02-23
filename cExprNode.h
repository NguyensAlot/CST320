/*****************************************************
 * Class: cExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Abstract base class for expressions
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cDeclNode.h"

using namespace std;

class cExprNode : public cAstNode
{
public:
    virtual cDeclNode* getType() = 0;
};