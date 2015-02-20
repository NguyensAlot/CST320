/*****************************************************
 * Class: cDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Abstract base class for declaractions
 * **************************************************/
#pragma once
#include "cAstNode.h"

using namespace std;

class cDeclNode : public cAstNode
{
public:
    virtual string toString() = 0;
};