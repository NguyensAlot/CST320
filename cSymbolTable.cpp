/*****************************************************
 * Class: cSymbolTable
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Implementation of cSymboTable.h
 * **************************************************/
#include "cSymbolTable.h"
#include "cBaseDecl.h"

using namespace std;

cSymbolTable::cSymbolTable()
{
    IncreaseScope();
    //starting the table with the type symbols
    cSymbol* character = new cSymbol("char");
    cSymbol* integer = new cSymbol("int");
    cSymbol* floating = new cSymbol("float");

    character->setType(new cBaseDecl("char", 1, false));
    integer->setType(new cBaseDecl("int", 4, false));
    floating->setType(new cBaseDecl("float", 8, true));
    
    Insert(character);
    Insert(integer);
    Insert(floating);
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
    cSymbol* retVal = nullptr;
    map<string,cSymbol*>::iterator it = mapList.front()->find(symbolCharPointer);
    
    if (it == mapList.front()->end())
    {
        retVal = new cSymbol(symbolCharPointer);
        mapList.front()->insert(pair<string,cSymbol*>(symbolCharPointer,retVal));
    }
    
    else 
    {
        retVal = it->second;
    }
    return retVal;
}
cSymbol* cSymbolTable::Insert(cSymbol* csymbol)
{
    mapList.front()->insert(pair<string,cSymbol*>(csymbol->getmSymbol(),csymbol));

    return csymbol;
}

// Searches for symbol by using the string
cSymbol* cSymbolTable::LookupSym(string symbol)
{
    //Iterator for list of maps
    for(list<map<string,cSymbol*>*>::iterator it = mapList.begin(); it != mapList.end(); ++it)
    {
        //Search map for symbol
        map<string,cSymbol*>::iterator it2 = (*it)->find(symbol);
        
        //If found, return symbol
        if(it2 != (*it)->end())
            return it2->second;
    }
    
    //return nothing
    return nullptr;
}