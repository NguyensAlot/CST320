/*****************************************************
 * Class: cArraySpec
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of arrays
 * **************************************************/
#pragma once

using namespace std;

class cArraySpec
{
public:  
    cArraySpec() {}
    string toString()
    {
        string strHolder;
        
        // iterate through list
        for  (list<int>::iterator it = _intList.begin(); it != _intList.end(); it++)
            strHolder += " " + to_string(*it);
        
        return "(ARRAYSPEC: " + strHolder + ")\n";
    }
    void addNode(int value)
    {
        _intList.push_back(value);
    }
private:
    list<int> _intList;
    
};