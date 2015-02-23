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
    virtual cDeclNode* getType()    { return this; }
    virtual bool IsType()           { return false; }
    virtual bool IsFunc()           { return false; }
    virtual bool IsInt()            { return false; }
    virtual bool IsFloat()          { return false; }
    virtual bool IsStruct()         { return false; }
    virtual bool IsArray()          { return false; }
    // gives size of data type
    virtual int getSize() = 0;
    // gives string type name
    virtual string stringType() = 0;
};