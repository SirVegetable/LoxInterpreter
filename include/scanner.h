#pragma once
#include "TokenTypes.h"
#include "token.h"
#include <string> 
#include <vector>
#include <unordered_map>


class Scanner
{
    public:
        Scanner(std::string src); 
        
        std::vector<Token> scan_source();
        void scan_token();
        
    private:
        std::string source; 
        std::vector<Token> tokens;
        int start = 0; 
        int current = 0; 
        int line = 1;
        std::unordered_map<std::string, TokenTypes> keywords;  
        

        // internal methods for scanning the source
        void add_token(TokenTypes type, std::any literal);
        void add_token(TokenTypes type); 
        bool match(const char& expected);
        bool at_end(); 
        char peek();
        void is_a_string(); 
        void is_a_number();
        char peek_next();
        bool is_alpha_numeric(char c); 
        void is_an_identifier(); 
        char advance(); 
        bool is_digit(const char& c); 


}; 