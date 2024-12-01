#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include<vector>
#include<string>

enum tokenType{
    WHITESPACE,
    IDENTIFIER,
    INT_LITERAL,
    STRING_LITERAL,
    OPERATOR
};

class Token{
public:
    enum tokenType mType{WHITESPACE};
    std::string mText;
    size_t mStartOffset{0};
    size_t mEndOffset{0};
    size_t mLineNumber{0};
};

class Tokenizer{
public:
    std::vector<Token> parse(const std::string& inProgram);
private:
    void endToken(Token& token, std::vector<Token>& tokens);
};

#endif