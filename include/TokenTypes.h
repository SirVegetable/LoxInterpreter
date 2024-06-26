
#pragma once 

enum class TokenTypes
{
    // Single-character tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, 
    COMMA, DOT, PLUS, MINUS, SEMICOLON, SLASH, STAR, 

    // One or Two character tokens S
    BANG, BANG_EQUAL, EQUAL, EQUAL_EQUAL, 
    GREATER, GREATER_EQUAL, 
    LESS, LESS_EQUAL,

    // literals
    IDENTIFIER, STRING, NUMBER,

    // keywords
    AND, OR, CLASS, IF, ELSE, FUN, FOR, NIL, FALSE,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    
    END
}; 