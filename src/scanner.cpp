#include "../include/scanner.h"
#include "../include/token.h"
#include "../include/tokentypes.h"
#include <any>

std::vector<Token> Scanner::scan_source()
{
    for(auto iter = source.begin(); iter != source.end(); ++iter)
    {
        scan_token(*iter); 
    }
    tokens.emplace_back(Token{TokenTypes::END,"",line}); 
    return tokens; 
}

void Scanner::scan_token(char c)
{
    
}

void Scanner::add_token(TokenTypes type, std::any literal)
{
    tokens.emplace_back(type,source.substr(start, current), literal, line); 
}