#include<iostream>
#include"Tokenizer.hpp"
#include<vector>
#include<string>

std::vector<Token> Tokenizer::parse(const std::string& inProgram){
    std::vector<Token> tokens;
    currentToken.mLineNumber = 1;
    //State Machine
    Token currentToken;
    for(char currentChar : inProgram){
        switch(currentChar){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(currentToke.mType == WHITESPACE){
                    currentToken.mType = INT_LITERAL;
                    currentToken.mText.append(1, currentChar);
                } else {
                    currentToken.mText.append(1, currentChar);
                }
                break;
            case '{':
            case '}':
            case '(':
            case ')':
            case '=':
            case ';':
            case '+':
            case '-':
            case ',':
                if(currentToken.mType != STRING_LITERAL){
                    endToken(currentToken);
                    currentToken.mType = OPERATOR;
                    currentToken.mText.append(1, currentChar);
                    endToken(currentToken);
                } else {
                    currentToken.mText.append(1, currentChar);
                }
                break;
            
            case ' ':
            case '\t':
                endToken(currentToken, tokens);
                break;
            case '\n':
                endToken(currentToken, tokens);
                ++currentToken.mLineNumber;
                break;

                default:
                    break;
        }
    }
    /*Working in this file currently. Minute 33:10 of the youtube
    video "Making a programming language (part 1): How to write a parser in C++"*/
    return tokens;
}

void Tokenizer::endToken(Token& token, std::vector<Token>& tokens){
    if(token.mType != WHITESPACE){
        tokens.push_back(token);
    }
    token.mType = WHITESPACE;
    token.mText.erase();
}