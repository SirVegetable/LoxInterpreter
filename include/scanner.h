#pragma once
#include "TokenTypes.h"
#include "token.h"
#include <string> 
#include <vector> 


class Scanner
{
    public:

        std::vector<Token> scan_source();
        void scan_token(char c);
        
    private:
        std::string source; 
        std::vector<Token> tokens;
        int start = 0; 
        int current = 0; 
        int line = 1;   
        

        // internal methods for scanning the source
        void add_token(TokenTypes type, std::any literal);
        void add_token(TokenTypes type); 
        bool match(char c);
        bool at_end(); 
        char peek();
        void is_a_string(); 
        void is_a_number(); 



}; 