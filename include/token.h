#pragma once

#include "TokenTypes.h"
#include <any>
#include <string>

class Token
{
    public:
        
        Token(TokenTypes tok_type, std::string lex, int j);              // Constructor for EOF when scanning

        Token(TokenTypes t, std::string l, std::any li, int i);          // Default Constructor
        
        std::string convert_to_string();

    private: 
        TokenTypes type;
        std::string lexeme;
        std::any literal; 
        int line;

    private:

        template<typename T>
        std::string literal_to_string(const T& value)
        {
            if(value == TokenTypes::NUMBER)
            {
                return std::to_string(static_cast<int>(value)); 
            }
            else if(value == TokenTypes::STRING)
            {
                return std::to_string(value); 
            }
            else 
            {
                return ""; 
            }


        }


}; 

