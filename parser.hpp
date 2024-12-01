#ifndef PARSER_HPP
#define PARSER_HPP
#include<iostream>
#include<string>
#include"string.hpp"

struct NumericLiteral {
    String type;
    double value;
};
struct Program {
    String type;
    NumericLiteral body;

    Program() : type("Program"), body() {}
};

class Parser{
public:
    //Constructor to initialize the parser with a string
    Parser(const String& input) : _string(input) {}
    
    Program program(){
        Program prog;
        prog.body = numericliteral();
        return prog;
    }
    //Main program method that returns numericLiteral
    // NumericLiteral program(){
    //     return numericliteral();
    // }
private:
    String _string;

    NumericLiteral numericliteral(){
        NumericLiteral literal;
        literal.type = "NumericLiteral";

        literal.value = std::stod(_string.c_str());
        return literal;
    }
};

#endif