/*******************************************
 * Author: Anthony Nguyen
 * Program: Lab 2 Recursive Descent Parser
 * Description:
 * 
 * 
 * 
*******************************************/
#include <iostream>
#include "lex.h"
#include "parse.h"
#include "tokens.h"

int yylval = 0;
int token = -1;
int oldToken = -1;


//*******************************************
int GetToken()
{
    if (token > 0)
    {
        oldToken = token;
        token = -1;
    } else {
        oldToken = yylex();
    }

    return oldToken;
}
//*******************************************
void Error(std::string expecting)
{
    std::cout << "Found " << yytext << " when expecting a " << expecting;
    std::cout << " in line " << yylineno << std::endl;
    int token = GetToken();
    while (token != ';' &&  token != END)       //received help
    {
        token = GetToken();
    }
}
//*******************************************
void UnGetToken()
{
    token = oldToken;
}
//*******************************************
bool FindPROG()
{
    if (FindSTMTS())
    {
        if (GetToken() == END)
        {
            return true;
        }
        Error("end");
        return false;
    }
    else 
    {
    Error("Program");
    return false;
    }
}
//*******************************************
bool FindSTMTS()
{
    if (!FindSTMT())
    {
        if (GetToken() == END)
        {
            UnGetToken();
            return true;
        }
        UnGetToken();
        if (!FindSTMTS())
            return true;
    }     
    else if (!FindSTMTS())
        return false;
        
    return true;
}
//*******************************************
bool FindSTMT()
{
    if(FindEXPR())
    {
        if (GetToken() == ';')
        {
            std::cout << "Found a statement\n";
            return true;
        }
        else 
        {
        Error("';'");
        return false;
        }
    }
    return false;
}
//*******************************************
bool FindEXPR()
{
    if (GetToken() == '(')
    {
        if (FindEXPR())
        {
            if (GetToken() == ')')
            {
                if (FindEXPR_P())
                {
                    return true;
                }
                return false;
            }
            Error("')'");
            return false;
        }
        return false;
    }
    UnGetToken();
    
    if (FindTERM())
    {
        return true;
    }
    return false;
}
//*******************************************
bool FindEXPR_P()
{
    if (FindPLUSOP())
    {
        if (GetToken() == '(')
        {
            if (FindEXPR())
            {
                if (GetToken() == ')')
                {
                    if (FindEXPR_P())
                    {
                        return true;
                    }
                }
                Error(")");
                return false;
            }
            Error("EXPR");
            return false;
        }
        Error("(");
        return false;
    }
    return true;
}
//*******************************************
bool FindPLUSOP()
{
    int token = GetToken();
    if (token == '+')
    {
        return true;
    }
    else if (token == '-')
    {
        return true;
    }
    UnGetToken();
    return false;
}
//*******************************************
bool FindTERM()
{
    int token = GetToken();
    if (token == '[')
    {
        if (FindEXPR())
        {
            if (GetToken() == ']')
            {
                if (FindTERM_P())
                {
                    return true;
                }
                return false;
            }
            Error("']'");
            return false;
        }
        return false;
    }
    
    else if (token == INT_VAL)
    {
        return true;
    }
    UnGetToken();
    return false;
}
//*******************************************
bool FindTERM_P()
{
    if (FindTIMESOP())
    {
        if (GetToken() == '[')
        {
            if (FindEXPR())
            {
                if (GetToken() == ']')
                {
                    if (FindTERM_P())
                    {
                        return true;
                    }
                    return false;
                }
                Error("']'");
                return false;
            }
            return false;
        }
        Error("'['");
        return false;
    }
    return true;
}
//*******************************************
bool FindTIMESOP()
{
    int token = GetToken();
    if (token == '*')
    {
        return true;
    }
    else if (token == '/')
    {
        return true;
    }
    UnGetToken();
    return false;
}
/*******************************************
bool FindExample()
{
    if (!FindPART1()) return false;
    
    int token = GetToken();
    if (token != '+')
    {
        UnGetToken();
        return false;
    }

    if (!FindPART2()) return false;

    return true;
}
*/

