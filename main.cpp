#include <iostream>
#include <fstream>
#include <cstdio>
#include "stack.hpp"
#include "string.hpp"
#include"parser.hpp"

// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//     {
//         std::cerr << "Usage: " << argv[0] << "<programFile> <outputFile>\n";
//         return 1;
//     }

//     FILE *programFile = fopen(argv[1], "r"); // open program file with reading permissions
//     if (!programFile)
//     {
//         std::cerr << "Error: Could not open program file (" << argv[1] << ") for reading.\n";
//         return 1;
//     }
//     FILE *outputFile = fopen(argv[2], "w"); // open output file with writing permissions.
//     if (!outputFile)
//     {
//         std::cerr << "Error: Could not open output file (" << argv[2] << ") for writing.\n";
//         fclose(programFile); // close program file, since output file couldn't be opened
//         return 1;
//     }
//     //Read the program file into a String Object
//     String programCode;
//     char BUFFER[1024];
//     while(fgets(BUFFER, sizeof(BUFFER), programFile)){
//         programCode += BUFFER;
//     }
//     fclose(programFile);
//     //Split the program into seperate lines

//     fclose(outputFile);
//     std::cout << "Proccessing complete. Output written to " << argv[2] << "\n";

// }

int main() {
    String input("1234.455");

    Parser parser(input);

    Program prog = parser.program();

    std::cout << "Program Type: " << prog.type << "\n";
    std::cout << "Body Type: " << prog.body.type << "\n";
    std::cout << "Body Value: " << prog.body.value << "\n";
}