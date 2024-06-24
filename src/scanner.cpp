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
    switch(c)
    {
        case '(': add_token(TokenTypes::LEFT_PAREN); break;
        case ')': add_token(TokenTypes::RIGHT_PAREN); break;
        case '{': add_token(TokenTypes::LEFT_BRACE); break;
        case '}': add_token(TokenTypes::RIGHT_BRACE); break;
        case ',': add_token(TokenTypes::COMMA); break;
        case '.': add_token(TokenTypes::DOT); break;
        case '+': add_token(TokenTypes::PLUS); break;
        case '-': add_token(TokenTypes::MINUS); break;
        case ';': add_token(TokenTypes::SEMICOLON); break;
        case '*': add_token(TokenTypes::STAR); break;
        
    }
}

void Scanner::add_token(TokenTypes type)
{

}
void Scanner::add_token(TokenTypes type, std::any literal)
{
    tokens.emplace_back(type,source.substr(start, current), literal, line); 
}