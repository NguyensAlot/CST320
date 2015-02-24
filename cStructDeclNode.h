/*****************************************************
 * Class: cStructDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of struct declaration
 * **************************************************/
#pragma once
#include "cDeclsNode.h"
#include "cSymbol.h"

using namespace std;

class cStructDeclNode : public cDeclNode
{
public:
    cStructDeclNode(map<string, cSymbol*>* symTable, cDeclsNode* decls, cSymbol* identifier)
    {
        _symTable = symTable;
        _decls = decls;
        _identifier = identifier;
    }
    
    string toString()
    {
        return "STRUCT: " + _decls->toString() + " " + _identifier->toString();
    }
    
    bool IsStruct()
    {
        return true;
    }
    
    int getSize()
    {
        return addSize();
    }
    
    int addSize()
    {
        int count = 0;
        
        for (map<string,cSymbol*>::iterator it = _symTable->begin(); it != _symTable->end(); it++)
            count += it->second->getType()->getSize();
            
        return count;
    }
    
    string stringType()
    {
        return _identifier->getmSymbol();
    }
    
    cSymbol* Find(string symbol)
    {
        cSymbol* sym = nullptr;
        
        if(_symTable != nullptr)
        {
            map<string,cSymbol*>::iterator it = _symTable->find(symbol);
            
            if(it != _symTable->end())
            {
                sym = it->second;
            }
        }
        return sym;
    }
    
private:
    map<string, cSymbol*>* _symTable;
    cDeclsNode* _decls;
    cSymbol* _identifier;
};