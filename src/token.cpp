#include "../include/token.h"

Token::Token(TokenTypes t, std::string l, std::any li, int i) : type{t} , lexeme{l}, literal{li}, line{i}
{}

std::string Token::convert_to_string()
{
    
}