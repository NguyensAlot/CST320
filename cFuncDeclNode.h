/*****************************************************
 * Class: cFuncDeclNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function declarations
 * **************************************************/
#pragma once
#include "cDeclsNode.h"
#include "cFuncHeader.h"
#include "cFuncPrefix.h"
#include "cStmtsNode.h"
 
using namespace std;

class cFuncDeclNode : public cDeclNode
{
public:
    cFuncDeclNode(cFuncHeader* header, cDeclsNode* decl = nullptr, cStmtsNode* stmt = nullptr)
    {
        _header = header;
        _decl = decl;
        _stmt = stmt;
    }
    
    string toString()
    {
        string strHolder = _header->toString();
        
        if (_decl != nullptr)
            strHolder += _decl->toString();
        if (_stmt != nullptr)
            strHolder += _stmt->toString();
            
        return "(FUNC: " + strHolder + "\n)";
    }
    
    int getSize()
    {
        return 0;
    }
    
    string stringType()
    {
        return _header->getTypeSymbol()->getmSymbol();
    }
    
private:
    cFuncHeader* _header;
    cDeclsNode* _decl;
    cStmtsNode* _stmt;
};