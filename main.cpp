#include <iostream>
#include <fstream>
#include <cstdio>
#include "stack.hpp"
#include "string.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << "<programFile> <outputFile>\n";
        return 1;
    }

    FILE *programFile = fopen(argv[1], "r"); // open program file with reading permissions
    if (!programFile)
    {
        std::cerr << "Error: Could not open program file (" << argv[1] << ") for reading.\n";
        return 1;
    }
    FILE *outputFile = fopen(argv[2], "w"); // open output file with writing permissions.
    if (!outputFile)
    {
        std::cerr << "Error: Could not open output file (" << argv[2] << ") for writing.\n";
        fclose(programFile); // close program file, since output file couldn't be opened
        return 1;
    }
    //Read the program file into a String Object
    String programCode;
    char BUFFER[1024];
    while(fgets(BUFFER, sizeof(BUFFER), programFile)){
        programCode += BUFFER;
    }
    fclose(programFile);
    //Split the program into seperate lines
    std::vector<String> lineOfCode = programCode.split('\n');

    if(lineOfCode.empty() || lineOfCode[0].trim(';') != "start func(){"){
        std::cerr << "Error: Program cannot begin without \"start func(){\"";
        fclose(outputFile);
        return 1;
    }

    Stack<String> codeStack;

    for(size_t i = 1; i < lineOfCode.size(); ++i){
        String currentLine = lineOfCode[i].trim(';');
        if(currentLine == "END}"){
            break;
        }
        if(!currentLine.isEmpty()){
            codeStack.push(currentLine);
        }
    }

    while(!codeStack.isEmpty()){
        String currentLine = codeStack.pop();

        std::vector<String> tokens = currentLine.split(' ');

        String valueToPrint;

        if(tokens.size() >= 3 && tokens[1] == "="){
            String varType = tokens[0];
            String varName = tokens[2];
            fprintf(outputFile, "Declare variable: Type %s, Name = %s\n", varType.c_str(), varName.c_str());
        } else if(tokens[0] == "out.to.console"){
            valueToPrint = tokens[1].trim(';');
            fprintf(outputFile, "Print to console: %s\n", valueToPrint.c_str());
        } else {
            valueToPrint = "Weird unsure why LOL TODO:";
            fprintf(outputFile, "Unknown command: %s\n", valueToPrint.c_str());
        }
    }
    for(const auto& line : lineOfCode){
        if(!line.isEmpty()){
            fprintf(outputFile, "%s\n", line.c_str());
        }
    }
    fclose(outputFile);
    std::cout << "Proccessing complete. Output written to " << argv[2] << "\n";

}