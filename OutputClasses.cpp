#include <iostream>
#include "OutputClasses.h"
#include "CustomString.h"
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

void FileOutput::write(CustomString &funcString)
{
    std::ofstream outputFile(filename);

    if (!outputFile)
    {
        std::cerr << "Could not open the file you've chose: " << filename << std::endl;
        return;
    }
    const char* content = funcString.getArray();
    outputFile << content;

    outputFile.close();
}

void ConsoleOutput::write(CustomString &funcString)
{
    funcString.print();
}