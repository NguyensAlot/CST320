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
    
    character->setIsType();
    integer->setIsType();
    floating->setIsType();
    
    Insert(character);
    Insert(integer);
    Insert(floating);
}

map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
    mapList.push_front(new map<string, cSymbol*>());
    
    return mapList.front();
}
        
void cSymbolTable::DecreaseScope()
{
    mapList.pop_front();
}

//brings in symbol and inserts it into default map
cSymbol* cSymbolTable::Insert(string symbolCharPointer)
{
    cSymbol* symbol = nullptr;
    map<string,cSymbol*>::iterator it = mapList.front()->find(symbolCharPointer);
    
    if (it == mapList.front()->end())
    {
        symbol = new cSymbol(symbolCharPointer);
        mapList.front()->insert(pair<string,cSymbol*>(symbolCharPointer,symbol));
    }
    
    else 
        symbol = it->second;
        
    return symbol;
}

cSymbol* cSymbolTable::Insert(cSymbol* csymbol)
{
    map<string,cSymbol*>::iterator it = mapList.front()->find(csymbol->getmSymbol());
    
    if (it == mapList.front()->end())
        mapList.front()->insert(pair<string,cSymbol*>(csymbol->getmSymbol(), csymbol));
        
    else 
        csymbol = it->second;
        
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

cSymbol* cSymbolTable::SeachLocal(string symbol)
{
    map<string, cSymbol *>::const_iterator it = mapList.front()->find(symbol);
    
    if (it == mapList.front()->end())
        return nullptr;
    else
        return it->second;
}