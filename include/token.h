#pragma once

#include "tokentypes.h"
#include <any>
#include <string>

class Token
{
    public: 
        Token(TokenTypes t, std::string l, std::any li, int i); 
        
        std::string convert_to_string(); 
    private: 
        TokenTypes type;
        std::string lexeme;
        std::any literal; 
        int line; 

}; 

