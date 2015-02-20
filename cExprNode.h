/*****************************************************
 * Class: cExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Abstract base class for expressions
 * **************************************************/
#pragma once
#include "cAstNode.h"

using namespace std;

class cExprNode : public cAstNode
{
public:
    virtual string toString() = 0;
};