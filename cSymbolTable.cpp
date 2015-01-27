#include "cSymbolTable.h"

cSymbolTable::cSymbolTable() {
}

void cSymbolTable::IncreaseScope() {
    mapStack.push(new map<string, cSymbol*>());
}
        
void cSymbolTable::DecreaseScope() {
    mapStack.pop();
}

/*******************************************
 * Function: Insert()
 * Description: Traverses through map to look
 *  for existing symbol. If found, returns 
 *  the value; if not, it is inserted into
 *  the map and then returned
 * 
 * Parameter:
 *  symPtr - inputed text
*******************************************/
cSymbol* cSymbolTable::Insert(string symPtr) {
    cSymbol * retVal = nullptr;
    map<string, cSymbol*>::iterator Iter = mapStack.top()->find(symPtr);
    
    if (Iter == mapStack.top()->end())
    {
        retVal = new cSymbol(symPtr);
        mapStack.top()->insert(pair<string, cSymbol*>(symPtr, retVal));
    }
    else 
    {
        retVal = Iter->second;
    }
    return retVal;
}