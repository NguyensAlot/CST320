/*****************************************************
 * Class: cFuncCall
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Anthony Nguyen
 * Description: Takes care of function calls
 * **************************************************/
#pragma once
#include "cExprNode.h"
#include "cParamsNode.h"
#include "cStmtNode.h"
#include "cSymbol.h"

class cFuncCall : public cStmtNode
{
public:
    cFuncCall(cSymbol* identifier, cParamsNode* params)
    {
        _identifier = identifier;
        _params = params;
    }
    string toString()
    {
        return "(FUNC CALL: " + _identifier->toString() + _params->toString() + ")";
    }
private:
    cSymbol* _identifier;
    cParamsNode* _params;
};
