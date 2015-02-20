/*****************************************************
 * Class: cScanNode
 * Author: Anthony Nguyen, Alexander Tappin
 * Primary: Alexander Tappin
 * Description: Takes care of scanning
 * **************************************************/
#pragma once
#include "cStmtNode.h"
#include "cExprNode.h"

class cScanNode : public cStmtNode
{
public:
    cScanNode(cExprNode* expr)
    {
        _expr = expr;
    }
    virtual string toString()
    {
        return "SCAN: " + _expr->toString();
    }
private:
    cExprNode* _expr;
};