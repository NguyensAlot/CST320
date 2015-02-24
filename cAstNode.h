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
#include <map>
#include <unordered_map>

using namespace std;

void semantic_error(string msg);

class cAstNode
{
public:
    virtual string toString() = 0;
    virtual bool SemanticError() { return error; }
    
protected:
    bool error = false;
};
