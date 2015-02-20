/*****************************************************
 * Class: cSymbol
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Abstract datatype that has sequence and symbol
 * **************************************************/
#pragma once
#include <iostream>
#include <string>

using namespace std;
class cSymbol
{
public:
    cSymbol(string symbol="", bool IsT = false);
    virtual string toString();
    string getmSymbol();
    bool isItType();
    void setTypeTrue();
protected:
    string mSymbol;
    bool isType;
    int mSequence;
    static int symbolCount;
};