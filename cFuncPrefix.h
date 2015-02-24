/*****************************************************
 * Class: cFuncPrefix
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function prefixes
 * **************************************************/
#pragma once
#include "cAstNode.h"
#include "cSymbol.h"
 
using namespace std;
 
class cFuncPrefix
{
public:
    cFuncPrefix(cSymbol* typeID, cSymbol* identifier)
    {
        _typeID = typeID;
        _identifier = identifier;
    }
    
    string toString()
    {
        return _identifier->toString();
    }
    
    cSymbol* getTypeSymbol()
    {
        return _typeID;
    }
    
private:
    cSymbol* _typeID;
    cSymbol* _identifier;
};