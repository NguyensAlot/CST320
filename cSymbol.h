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
    // _declNode setter/getter
    void setType(cDeclNode* declNode);
    cDeclNode* getType();
    // _declared setter/getter
    void setDeclared();
    bool getDeclared();
    // isType setter/getter
    void setIsType();
    bool getIsType();
    
protected:
    string mSymbol;
    int mSequence;
    static int symbolCount;
    // for getting variable types
    cDeclNode* _declNode;
    // for checking if declared
    bool _declared;
    // for checking if type
    bool isType;
};