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
    //bool isItType();
    //void setTypeTrue();
    cDeclNode* getType();
    void setType(cDeclNode* declNode);
    
protected:
    string mSymbol;
    //bool isType;
    int mSequence;
    static int symbolCount;
    cDeclNode* _declNode;
};