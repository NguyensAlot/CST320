/*******************************************
 * Student: Anthony Nguyen  anthony.nguyen@oit.edu
 * File: cSymbolTable.h
 * Description: Header file for cSymbolTable
 *  class implementation
 * 
 * 
*******************************************/

#pragma once
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include "cSymbol.h"

using namespace std;

class cSymbolTable
{
public:
    cSymbolTable();
    void IncreaseScope();
    void DecreaseScope();
    cSymbol* Insert(string symbol);
    
private:
    stack<map<string, cSymbol*>*> mapStack;
};