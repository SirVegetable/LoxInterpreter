#include "../include/token.h"
#include "../include/TokenTypes.h"
#include <string>


Token::Token(TokenTypes tok_type, std::string lex, int j) : type{tok_type} , lexeme{lex}, line{j}
{}


Token::Token(TokenTypes t, std::string l, std::any li, int i) : type{t} , lexeme{l}, literal{li}, line{i}
{}

std::string Token::convert_to_string()
{
    auto first = std::to_string(static_cast<int>(type));
   
    return first + " " + lexeme + " " + literal_to_string(literal);   
}
