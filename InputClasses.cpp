#include <iostream>
#include "InputClasses.h"
#include "CustomString.h"
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

void ConsoleInput::read(CustomString& funcString)  
{
    std::cout << "Input text data and terminate by Control + D:\n" << std::endl;
    char ch;
    while (std::cin.get(ch)) 
    {
        if (funcString.sizeOfArray() == funcString.capacityOfArray()) 
        {
            funcString.expandArray();
        }
        *(funcString.getArray() + funcString.sizeOfArray()) = ch;
        funcString.incrementSize();
        
    }

    if (funcString.capacityOfArray() <= funcString.sizeOfArray())
    {
        funcString.expandArray();
    }

    *(funcString.getArray() + funcString.sizeOfArray()) = '\0';
}

void FileInput::read(CustomString& funcString) 
{
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Could not open the file you've chose: " << filename << std::endl;
        return;
    }
    char ch;
    while (file.get(ch))
    {
        funcString.addElement(ch);
    }
    file.close();
}