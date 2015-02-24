/*****************************************************
 * Class: cBaseDecl
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable declarations
 * **************************************************/
#pragma once
#include "cDeclNode.h"
#include "cSymbol.h"

using namespace std;

class cBaseDecl : public cDeclNode
{
public:
    cBaseDecl(string typeName, int size, bool isFloat, bool isChar)
    {
        _typeName = typeName;
        _size = size;
        _isFloat = isFloat;
        _isChar = isChar;   
    }
    
    bool IsInt()    { return !_isFloat; }
    bool IsFloat()  { return _isFloat; }
    bool IsType()   { return true; }
    bool IsChar()   { return _isChar; }
    string toString()
    {
        return "poop is compilers";
    }

    int getSize()
    {
        return _size;
    }
    
    string stringType()
    {
        return _typeName;
    }
protected:
    string _typeName;
    int _size;
    bool _isFloat;
    bool _isChar;
};


