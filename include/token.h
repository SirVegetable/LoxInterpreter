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

