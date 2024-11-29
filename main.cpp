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
}