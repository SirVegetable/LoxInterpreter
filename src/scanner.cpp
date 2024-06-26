#include "../include/scanner.h"
#include "../include/token.h"
#include "../include/tokentypes.h"
#include <any>
#include <memory>
#include <string>

Scanner::Scanner(std::string src) : source(src)
{
    keywords.emplace("and", TokenTypes::AND);
    keywords.emplace("class", TokenTypes::CLASS);  
    keywords.emplace("else", TokenTypes::ELSE); 
    keywords.emplace("for", TokenTypes::FOR);
    keywords.emplace("if", TokenTypes::IF);



}

std::vector<Token> Scanner::scan_source()
{
    while(!at_end())
    {
        start = current; 
        scan_token(); 
    }
    tokens.emplace_back(Token{TokenTypes::END,"",line}); 
    return tokens; 
}

void Scanner::scan_token()
{
    auto c = advance(); 
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
        case '!': add_token(match('=') ? TokenTypes::BANG : TokenTypes::BANG_EQUAL); break;
        case '=': add_token(match('=') ? TokenTypes::EQUAL_EQUAL : TokenTypes::EQUAL); break; 
        case '<': add_token(match('=') ? TokenTypes::LESS_EQUAL : TokenTypes::LESS); break;
        case '>': add_token(match('=') ? TokenTypes::GREATER_EQUAL : TokenTypes::GREATER); break;
        case '/':
            if(match('/'))
                {
                    while(peek() != '\n' && !at_end())
                    {
                        advance(); 
                    }
                }
            else 
            {
                add_token(TokenTypes::SLASH); 
            }
            break;
        case ' ': 
        case '\r': 
        case '\t':
            break;
        case '\n':
            line++; 
            break;  
        case '"': is_a_string();  break; 

        default: 
            if(is_digit(c))
            {
                is_a_number(); 
            }
            else if(is_alpha_numeric(c))
            {
                is_an_identifier();
            }
            else
            {
                /* Error here unexpected character, should report line as well*/
            }
            break;    
    }
}

bool Scanner::at_end()
{
    if(current >= source.length()) {return true;}
    return false; 
}

void Scanner::add_token(TokenTypes type)
{
    tokens.emplace_back(type,source.substr(start, current),line); 
}

void Scanner::add_token(TokenTypes type, std::any literal)
{
    tokens.emplace_back(type,source.substr(start, current), literal, line); 
}

bool Scanner::match(const char& expected)
{
    if(at_end()) { return false; }

    if(source[current] != expected ) { return false; }

    ++current; 
    return true; 
}

char Scanner::peek()
{
    if(at_end())
    {
        return '\0'; 
    }
    return source[current]; 
}

void Scanner::is_a_string()
{
    while(peek() != '"' && !at_end())
    {
        if(peek() == '\n'){line++;}
        advance(); 
    }
    if(at_end())
    {
        /* error needs to be handled, show line occured at*/
        return; 
    }
   
    advance();

    // Strip quotes for the token
    auto value = source.substr(start + 1, current -1); 
    add_token(TokenTypes::STRING, value); 
}


void Scanner::is_a_number()
{
    while(is_digit(peek())){ advance(); }
    
    if(peek() == '.' && is_digit(peek_next()))
    {
        advance(); 
        while(is_digit(peek())){advance(); } 
    }
    add_token(TokenTypes::NUMBER, std::stod(source.substr(start,current))); 
}

char Scanner::peek_next()
{
    if(current + 1 >= source.length()){return '\0'; }
    return source.at(current+1); 
}

void Scanner::is_an_identifier()
{
    while(is_alpha_numeric(peek()))
    {
        advance(); 
    } 
    add_token(TokenTypes::IDENTIFIER); 
}

char Scanner::advance()
{
    return source[current++]; 
}

bool Scanner::is_digit(char const& c)
{
    return c >= '0' && c <= '9'; 
}

bool is_alpha_numeric(const char& c )
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'; 
}
