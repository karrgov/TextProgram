#define _CRT_SECURE_NO_WARNINGS
#include "OperationClasses.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

void RemoveWord::transform(CustomString& funcString)
{
    int i = 0;
    int streamLength = funcString.sizeOfArray();
    int wordLength = strlen(wordToBeRemoved);
    while(i < streamLength)
    {
        if(strstr((funcString.getArray() + i), wordToBeRemoved) == (funcString.getArray() + i))
        {
            streamLength -= wordLength;
            for(int j = i; j < streamLength; j++)
            {
                *(funcString.getArray() + j) = *(funcString.getArray() + j + wordLength);
            }
        }
        else
        {
            i++;
        }
    }
    *(funcString.getArray() + i) = '\0';
}

void RemoveLineContainingWord::transform(CustomString& funcString)
{
    char* inputText = funcString.getArray();
    int inputLength = funcString.sizeOfArray();

    int startIndex = 0;
    int endIndex = 0;
    int j = 0;

    while (endIndex <= inputLength) 
    {
        if (inputText[endIndex] == '\n' || inputText[endIndex] == '\0') 
        {
            char* line = new char[endIndex - startIndex + 1];
            strncpy(line, inputText + startIndex, endIndex - startIndex);
            line[endIndex - startIndex] = '\0';

            if (strstr(line, wordToBeRemoved) == nullptr) 
            {
                strncpy(inputText + j, line, endIndex - startIndex);
                j += endIndex - startIndex;
                inputText[j] = '\n';
                j++;
            }

            startIndex = endIndex + 1;
            delete[] line;
        }
        ++endIndex;
    }

    inputText[j] = '\0';
    funcString.setSize(j);
}

void RemoveSymbol::transform(CustomString& funcString)
{
    int length = funcString.sizeOfArray();

    int j = 0;

    for(int i = 0; i < length; i++)
    {
        if(*(funcString.getArray() + i) != symbolToBeRemoved)
        {
            *(funcString.getArray() + j) = *(funcString.getArray() + i);
            j++;
        }
    }
    *(funcString.getArray() + j) = '\0';
}

void ReplaceWord::transform(CustomString& funcString)
{
    int toBeReplacedLength = strlen(toBeReplaced); 
        int replaceWordLength = strlen(replaceWord);
        int oldStreamLength = funcString.sizeOfArray();

        char* afterStream;
        if(toBeReplacedLength == replaceWordLength)
        {
            afterStream = (char*) malloc((oldStreamLength + 1) * sizeof(char));
        }
        else
        {
            int occurrencesOfToBeReplaced = 0;

            int i = 0;
            while(i < oldStreamLength)
            {
                if((strstr((funcString.getArray() + i), toBeReplaced)) == (funcString.getArray() + i))
                {
                    occurrencesOfToBeReplaced++;
                    i += oldStreamLength;
                }
                else
                {
                    i++;
                }
            }
            int diffInLength = replaceWordLength - toBeReplacedLength;
            int newStreamLength = oldStreamLength;
            newStreamLength += occurrencesOfToBeReplaced * diffInLength; //if diffInLength is positive then newStreamLength will be more than oldStreamLength
            //if diffInLength is negative then newStreamLength will be less than oldStreamLength
            afterStream = (char*) malloc((newStreamLength + 1) * sizeof(char));
        }
        //now we have already allocated the needed memory and we should actually replace the words

        int i = 0;
        int j = 0;

        while(i < oldStreamLength)
        {
            if((strstr((funcString.getArray() + i), toBeReplaced)) == (funcString.getArray() + i))
            {
                strcpy((afterStream + j), replaceWord);
                i += toBeReplacedLength;
                j += replaceWordLength;
            }
            else 
            {
                *(afterStream + j) = *(funcString.getArray() + i);
                i++;
                j++;
            }
        }
        *(afterStream + j) = '\0';
        funcString.setData(afterStream);
        delete[] afterStream;
}

void RemovePunctuation::transform(CustomString& funcString)
{
    int length = funcString.sizeOfArray();

    int j = 0;

    for(int i = 0; i < length; i++)
    {
        if(*(funcString.getArray() + i) != '.' && *(funcString.getArray() + i) != '!' && *(funcString.getArray() + i) != '?')
        {
            *(funcString.getArray() + j) = *(funcString.getArray() + i);
            j++;
        }
    }
    *(funcString.getArray() + j) = '\0';
}

void AddNewLineAfterSentence::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();

    char* outputText = new char[2 * inputLength + 1];
    int j = 0;

    for (int i = 0; i < inputLength; ++i) 
    {
        *(outputText + j) = *(funcString.getArray() + i);
        j++;

        if (*(funcString.getArray() + i) == '.' || *(funcString.getArray() + i) == '?' || *(funcString.getArray() + i) == '!') 
        {
            *(outputText + j) = '\n';
            j++;
        }
    }
    *(outputText + j) = '\0';

    funcString.setData(outputText);

    return outputText;
}

char* AddNewLineAfterEachWord::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();

    char* outputText = new char[2 * inputLength + 1];
    int j = 0;

    for (int i = 0; i < inputLength; ++i) 
    {
        *(outputText + j) = *(funcString.getArray() + i);
        j++;

        if (*(funcString.getArray() + i) == ' ') 
        {
            *(outputText + j) = '\n';
            j++;
        }
    }
    *(outputText + j) = '\0';

    funcString.setData(outputText);

    return outputText;
}

char* AddNewLineEveryKSymbols::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();

    char* outputText = new char[2 * inputLength + 1];
    int j = 0;

    for (int i = 0; i < inputLength; ++i) 
    {
        *(outputText + j) = *(funcString.getArray() + i);
        j++;

        if ((i + 1) % k == 0) 
        {
            *(outputText + j) = '\n';
            j++;
        }
    }
    *(outputText + j) = '\0';

    funcString.setData(outputText);

    return outputText;
}

char* RemoveNewLines::transform(CustomString& funcString)
{
    int length = funcString.sizeOfArray();

    int j = 0;

    for(int i = 0; i < length; i++)
    {
        if(*(funcString.getArray() + i) != '\n')
        {
            *(funcString.getArray() + j) = *(funcString.getArray() + i);
            j++;
        }
    }
    *(funcString.getArray() + j) = '\0';
}

char* SortAlphabeticallyAllLines::transform(CustomString& funcString)
{
    
}

char* RemoveDuplicateLines::transform(CustomString& funcString)
{
    char* inputText = funcString.getArray();
    int inputLength = funcString.sizeOfArray();

    // Подготвяме динамичен масив за съхранение на уникални редове
    char** uniqueLines = new char*[inputLength];
    int uniqueLinesCount = 0;

    // Проходим през оригиналния текст и добавяме всеки уникален ред в новия масив
    int startIndex = 0;
    int endIndex = 0;
    while (endIndex <= inputLength) 
    {
        if (inputText[endIndex] == '\n' || inputText[endIndex] == '\0') 
        {
            std::string line(inputText + startIndex, endIndex - startIndex);

            // Проверяваме дали редът е уникален
            bool isUnique = true;
            for (int i = 0; i < uniqueLinesCount; ++i) {
                if (strcmp(line.c_str(), uniqueLines[i]) == 0) {
                    isUnique = false;
                    break;
                }
            }

            // Ако редът е уникален, го добавяме в новия масив
            if (isUnique) {
                uniqueLines[uniqueLinesCount] = new char[line.length() + 1];
                strcpy(uniqueLines[uniqueLinesCount], line.c_str());
                ++uniqueLinesCount;
            }

            startIndex = endIndex + 1;
        }
        ++endIndex;
    }

    // Създаваме нов символен низ с уникалните редове
    char* outputText = new char[inputLength + 1];
    int outputIndex = 0;
    for (int i = 0; i < uniqueLinesCount; ++i) 
    {
        int lineLength = strlen(uniqueLines[i]);
        strncpy(outputText + outputIndex, uniqueLines[i], lineLength);
        outputIndex += lineLength;
        outputText[outputIndex++] = '\n';

        // Освобождаваме паметта на текущия уникален ред
        delete[] uniqueLines[i];
    }

    // Освобождаваме паметта на динамичния масив от уникални редове
    delete[] uniqueLines;

    // Завършваме новия текст с терминираща нула
    outputText[outputIndex] = '\0';

    // Освобождаваме паметта на оригиналния текст
    delete[] inputText;

    // Обновяваме оригиналния текст с новия текст и обновяваме дължината му
    funcString.setData(outputText);

    return outputText;
}

char* CountLines::transform(CustomString& funcString)
{
    
}

char* CountSymbols::transform(CustomString& funcString)
{
    
}

