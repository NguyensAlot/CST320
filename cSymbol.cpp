/*****************************************************
 * Class: cSymbol
 * Author: Anthony Nguyen, Alexander Tappin
 * 
 * Description: Implementation of cSymbol.h
 * **************************************************/
#include "cSymbol.h"

int cSymbol::symbolCount= 0;

cSymbol::cSymbol(string symbol)
{
    mSymbol = symbol;
    mSequence = ++symbolCount;
}

string cSymbol::toString()
{
    return "sym: " + mSymbol + " " + to_string(mSequence);
}

string cSymbol::getmSymbol()
{
    return mSymbol;
}

// _declNode setter/getter
void cSymbol::setType(cDeclNode* declNode)
{
    _declNode = declNode;
}
cDeclNode* cSymbol::getType()
{
    return _declNode;
}

// _declared setter/getter
void cSymbol::setDeclared()
{
    _declared = true;
}
bool cSymbol::getDeclared()
{
    return _declared;
}

// isType setter/getter
void cSymbol::setIsType()
{
    isType = true;
}
bool cSymbol::getIsType()
{
    return isType;
}