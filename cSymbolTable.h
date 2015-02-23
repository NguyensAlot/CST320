/*****************************************************
 * Class: cSymbolTable
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of cSymbol maps
 * **************************************************/
#pragma once
#include <iostream>
#include <list>
#include <map>
#include <string>

#include "cSymbol.h"

using namespace std;

class cSymbolTable
{
public:
    cSymbolTable();
    map<string,cSymbol*>* IncreaseScope();
    void DecreaseScope();
    cSymbol* Insert(string symbol);
    cSymbol* Insert(cSymbol* symbol);
    cSymbol* LookupSym(string symbol);
    cSymbol* SeachLocal(string symbol);
    
private:
    list<map<string, cSymbol*>*> mapList;
};