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

/*bool cSymbol::isItType()
{
    return isType;
}

void cSymbol::setTypeTrue()
{
    isType = true;
}*/

cDeclNode* cSymbol::getType()
{
    return _declNode;
}

void cSymbol::setType(cDeclNode* declNode)
{
    _declNode = declNode;
}