/*****************************************************
 * Class: cAstNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Abstract base class for abstract syntax tree
 * **************************************************/
#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class cAstNode
{
public:
    virtual string toString() = 0;
    virtual bool SemanticError() { return false; }
    
protected:
    bool error = false;
};
