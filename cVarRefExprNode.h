/*****************************************************
 * Class: cVarRefExprNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of variable referencing
 * **************************************************/
#pragma once
#include "cExprNode.h"
#include "cVarPartNode.h"
#include "cStructDeclNode.h"

using namespace std;

class cVarRefExprNode : public cExprNode
{
public:
    cVarRefExprNode() {}
    
    string toString()
    {
        string strHolder;
        
        for  (list<cVarPartNode*>::iterator it = _varList.begin(); it != _varList.end(); it++)
            strHolder += "(VarRef: " + (*it)->toString();
        
        // changed how to output VarRef
        for(int i = _varList.size() -1; i >= 0; --i)
            strHolder += ")";
        
        return strHolder;
    }
    
    void addNode(cVarPartNode* var)
    {
        // add to the back of the list
        if (!isValid(var))
            _varList.push_back(var);
    }
    
    cDeclNode* getType()
    {
        return (*_varList.rbegin())->getType();
    }
    
    bool isValid(cVarPartNode* symbol)
    {
        // check size
        if(_varList.size() == 0)
        {   
            // check if declared
            if(!symbol->getSym()->getDeclared())
            {
                semantic_error("Symbol " + symbol->getSym()->getmSymbol() + " not defined");
                return true;
            }
        }
        else
        {
            cStructDeclNode* decl = dynamic_cast<cStructDeclNode*>(_varList.back()->getType());
            
            // if converted
            if (decl != nullptr)
            {
                // find cSymbol in structs
                cSymbol * sym = decl->Find(symbol->getSym()->getmSymbol());
                
                // if cSymbol found, valid
                if(sym != nullptr)
                {
                    symbol->setSym(sym);
                    return false;
                }
                // not valid
                else
                {
                    string msg = symbol->getSym()->getmSymbol() + " is not a field of ";
                    
                    semantic_error(msg + ErrorMsg());
                    
                    return true;
                }
            }
            // not a struct, not valid
            else
            {
                semantic_error(ErrorMsg() + " is not a struct");
                return true;
            }
        }
        return false;
    }
    
    string ErrorMsg()
    {
        string msg = "";
        int counter = _varList.size() - 1;
        
        for (list<cVarPartNode*>::const_iterator it = _varList.begin(); it != _varList.end(); it++)
        {
            // concatenate to error message
            msg += (*it)->getSym()->getmSymbol();
            
            // place '.' if looking at struct field
            if (counter != 0)
                msg += '.';
                
            counter--;
        }
        return msg;
    }
    
private:
    list<cVarPartNode*> _varList;
};