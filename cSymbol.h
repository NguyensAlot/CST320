/*****************************************************
 * Class: cSymbol
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Abstract datatype that has sequence and symbol
 * **************************************************/
#pragma once
#include <iostream>
#include <string>
#include "cDeclNode.h"

using namespace std;
class cSymbol
{
public:
    cSymbol(string symbol="");
    virtual string toString();
    string getmSymbol();
    
    // getters and setters for new member variable
    cDeclNode* getType();
    void setType(cDeclNode* declNode);
    
protected:
    string mSymbol;
    int mSequence;
    static int symbolCount;
    cDeclNode* _declNode;
};