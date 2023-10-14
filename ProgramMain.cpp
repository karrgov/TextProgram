#define _CRT_SECURE_NO_WARNINGS
#include "DynamicArray.h"
#include "CustomString.h"
#include "InputClasses.h"
#include "OperationClasses.h"
#include "OutputClasses.h"
#include "GroupClasses.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

int main()
{
    try
    {
        /*
        DynamicArray<char> testArr(3);
        testArr.push_back('d');
        testArr.push_back('f');

        for(int i = 0; i < testArr.getSize(); i++)
        {
            std::cout << *(testArr.getArray() + i) << std::endl;
        }
        */

        CustomString string;

        //FileInput fileIn("WriteFromFile.txt");
        //FileOutput fileOut("Text.txt");

        //fileIn.read(string);
        //fileOut.write(string);

        ConsoleInput console;
        //console.read(string);

        RemoveWord operation1("krasi");
        RemoveLineContainingWord operation2("haha");
        RemoveSymbol operation3('c');
        ReplaceWord operation4("apple", "nok");
        RemovePunctuation operation5;
        AddNewLineAfterSentence operation6;
        AddNewLineAfterEachWord operation7;
        AddNewLineEveryKSymbols operation8(2);
        RemoveNewLines operation9;
        RemoveDuplicateLines operation10;
        CountLines operation11;
        CountSymbols operation12;

        ConsoleOutput consoleW;
        //consoleW.write(string);

        DynamicArray<Input*> inputs(2);
        DynamicArray<TextOperation*> operations(2);
        DynamicArray<Output*> outputs(2);

        inputs.push_back(&console);
        operations.push_back(&operation1);
        //operations.push_back(&operation2);
        //operations.push_back(&operation3);
        //operations.push_back(&operation4);
        //operations.push_back(&operation5);
        //operations.push_back(&operation6);
        //operations.push_back(&operation7);
        //operations.push_back(&operation8);
        //operations.push_back(&operation9);
        //operations.push_back(&operation10);
        //operations.push_back(&operation11);
        //operations.push_back(&operation12);
        outputs.push_back(&consoleW);


        Group firstGroup(string, inputs, operations, outputs);

        firstGroup.execute();
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}