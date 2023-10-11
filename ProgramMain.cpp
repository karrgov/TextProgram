#define _CRT_SECURE_NO_WARNINGS
#include "DynamicArray.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

int main()
{
    DynamicArray<char> testArr(3);
    testArr.push_back('d');
    testArr.push_back('f');

    for(int i = 0; i < testArr.getSize(); i++)
    {
        std::cout << *(testArr.getArray() + i) << std::endl;
    }



}