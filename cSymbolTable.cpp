/*****************************************************
 * Class: cSymbolTable
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Implementation of cSymboTable.h
 * **************************************************/
#include "cSymbolTable.h"

using namespace std;

cSymbolTable::cSymbolTable()
{
    IncreaseScope();
    //starting the table with the type symbols
    cSymbol* character = new cSymbol("char", true);
    cSymbol* integer = new cSymbol("int", true);
    cSymbol* floatingPoint = new cSymbol("float", true);
    
    Insert(character);
    Insert(integer);
    Insert(floatingPoint);
}

void cSymbolTable::IncreaseScope()
{
    mapList.push_front(new map<string, cSymbol*>());
}
        
void cSymbolTable::DecreaseScope()
{
    mapList.pop_front();
}

//brings in symbol and inserts it into default map
cSymbol* cSymbolTable::Insert(string symbolCharPointer)
{
    cSymbol * retVal = nullptr;
    map<string,cSymbol*>::iterator it = mapList.front()->find(symbolCharPointer);
    
    if (it == mapList.front()->end())
    //if (it == mapStack.top()->end())
    {
        retVal = new cSymbol(symbolCharPointer);
        mapList.front()->insert(pair<string,cSymbol*>(symbolCharPointer,retVal));
        //mapStack.top()->insert(pair<string,cSymbol*>(symbolCharPointer,retVal));
    }
    
    else 
    {
        retVal = it->second;
    }
    return retVal;
}
cSymbol* cSymbolTable::Insert(cSymbol* csymbol)
{
    cSymbol * retVal = nullptr;
    
    //now passing in the csymbol mSymbol instead of the string in the parameters
    map<string,cSymbol*>::iterator it = mapList.front()->find(csymbol->getmSymbol());
    
    if (it == mapList.front()->end())
    {
        mapList.front()->insert(pair<string,cSymbol*>(csymbol->getmSymbol(),csymbol));
    }
    else 
    {
        csymbol = it->second;
    }
    return retVal;
}

cSymbol* cSymbolTable::LookupSym(string symbol)
{
    //Iterator for list of maps
    list<map<string,cSymbol*>*>::iterator tableList;
    for(tableList = mapList.begin(); tableList != mapList.end(); ++tableList)
    {
        //Search map for symbol
        map<string,cSymbol*>::iterator sym = (*tableList)->find(symbol);
        
        //If found return symbol
        if(sym != (*tableList)->end())
            return sym->second;
    }
    
    //return nothing
    return nullptr;
};