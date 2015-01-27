#include "cSymbol.h"

int cSymbol::symbolCount= 0;

cSymbol::cSymbol(string symbol)
{
    mSymbol = symbol;
    mSequence = ++symbolCount;
}

/*******************************************
 * Function: toString()
 * Description: outputs answers
*******************************************/
string cSymbol::toString()
{
    return "sym: " + mSymbol + " " + to_string(mSequence);
}