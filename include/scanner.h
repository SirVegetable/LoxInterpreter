#pragma once
#include "token.h"
#include <string> 
#include <vector> 


class Scanner
{
    public:

        std::vector<Token> scan_source();
        void scan_token(char c);
        void add_token(TokenTypes type, std::any literal);
        void add_token(TokenTypes type); 

    private:
        std::string source; 
        std::vector<Token> tokens;
        int start = 0; 
        int current = 0; 
        int line = 1; 


}; 