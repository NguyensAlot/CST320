/*****************************************************
 * Class: cFuncPrefix
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function prefixes
 * **************************************************/
#pragma once
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
    virtual string toString()
    {
        return _identifier->toString();
    }
private:
    cSymbol* _typeID;
    cSymbol* _identifier;
};