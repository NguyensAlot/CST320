/*******************************************
 * Student: Anthony Nguyen  anthony.nguyen@oit.edu
 * File: cSymbol.h 
 * Description: Header file for cSymbol class
 *  implementation.
*******************************************/

#ifndef CSYMBOL_H
#define CSYMBOL_H

#pragma once
#include <iostream>
#include <string>

using namespace std;

class cSymbol
{
public:
    cSymbol(string symbol="");
    virtual string toString();
    
protected:
    string mSymbol;
    int mSequence;
    static int symbolCount;
};

#endif