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

    character->setType(new cBaseDecl("char", 1, false, true));
    integer->setType(new cBaseDecl("int", 4, false, false));
    floating->setType(new cBaseDecl("float", 8, true, false));
    
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
    cSymbol * retVal = nullptr;
    map<string,cSymbol*>::iterator it = mapList.front()->find(symbolCharPointer);
    
    if (it == mapList.front()->end())
    //if (it == mapStack.top()->end())
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
    //now passing in the csymbol mSymbol instead of the string in the parameters
    map<string,cSymbol*>::iterator it = mapList.front()->find(csymbol->getmSymbol());
    
    if (it == mapList.front()->end())
    {
        if(LookupSym(csymbol->getmSymbol()) == csymbol)
            csymbol = Insert(csymbol->getmSymbol());
        else
            mapList.front()->insert(pair<string,cSymbol*>(csymbol->getmSymbol(), csymbol));
    }
    else 
    {
        csymbol = it->second;
    }
    return csymbol;
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
}

cSymbol* cSymbolTable::SearchLocal(string symbol)
{
    map<string, cSymbol *>::const_iterator it = mapList.front()->find(symbol);
    
    if (it == mapList.front()->end())
        return nullptr;
    else
        return it->second;
}
