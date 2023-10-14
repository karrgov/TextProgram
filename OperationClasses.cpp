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
    funcString.setSize(streamLength);
}

void RemoveLineContainingWord::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();

    int startIndex = 0;
    int endIndex = 0;
    int j = 0;

    while (endIndex <= inputLength) 
    {
        if (*(funcString.getArray() + endIndex) == '\n' || *(funcString.getArray() + endIndex) == '\0') 
        {
            char* line = new char[endIndex - startIndex + 1];
            strncpy(line, funcString.getArray() + startIndex, endIndex - startIndex);
            line[endIndex - startIndex] = '\0';

            if (strstr(line, wordToBeRemoved) == nullptr) 
            {
                strncpy(funcString.getArray() + j, line, endIndex - startIndex);
                j += endIndex - startIndex;
                *(funcString.getArray() + j) = '\n';
                j++;
            }

            startIndex = endIndex + 1;
            delete[] line;
        }
        ++endIndex;
    }

    *(funcString.getArray() + j) = '\0';
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
    funcString.setSize(length - (length - j));
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
    funcString.setSize(length - (length - j));
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
    delete[] outputText;
}

void AddNewLineAfterEachWord::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();

    char* outputText = new char[2 * inputLength + 1];
    int j = 0;

    for (int i = 0; i < inputLength; ++i) 
    {
        *(outputText + j) = *(funcString.getArray() + i);
        j++;

        if (*(funcString.getArray() + i) == ' ' && *(funcString.getArray() + i + 1) != ' ') 
        {
            *(outputText + j) = '\n';
            j++;
        }
    }
    *(outputText + j) = '\0';

    funcString.setData(outputText);
    delete[] outputText;

}

void AddNewLineEveryKSymbols::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();

    char* outputText = new char[2 * inputLength + 1];
    int j = 0;

    for (int i = 0; i < inputLength; ++i) 
    {
        *(outputText + j) = *(funcString.getArray() + i);
        j++;

        if ((i + 1) % k == 0 && *(funcString.getArray() + i + 1) == ' ') 
        {
            
            *(outputText + j) = '\n';
            j++;
        }
    }
    *(outputText + j) = '\0';

    funcString.setData(outputText);
    delete[] outputText;
}

void RemoveNewLines::transform(CustomString& funcString)
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
    funcString.setSize(length - (length - j));
}

void SortAlphabeticallyAllLines::transform(CustomString& funcString)
{
    
}

void RemoveDuplicateLines::transform(CustomString& funcString)
{
    int inputLength = funcString.sizeOfArray();
    char** uniqueLines = new char*[inputLength];
    int uniqueLinesCount = 0;
    int startIndex = 0;
    int endIndex = 0;

    while (endIndex <= inputLength) 
    {
        if (*(funcString.getArray() + endIndex) == '\n' || *(funcString.getArray() + endIndex) == '\0') 
        {
            int lineLength = endIndex - startIndex;
            char* line = new char[lineLength + 1];
            strncpy(line, funcString.getArray() + startIndex, lineLength);
            *(line + lineLength) = '\0';

            bool isUnique = true;
            for (int i = 0; i < uniqueLinesCount; ++i) 
            {
                if (strcmp(line, *(uniqueLines + i)) == 0) 
                {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) 
            {
                *(uniqueLines + uniqueLinesCount) = line;
                ++uniqueLinesCount;
            } 
            else 
            {
                delete[] line;
            }
            startIndex = endIndex + 1;
        }
        ++endIndex;
    }

    int totalOutputLength = 0;
    for (int i = 0; i < uniqueLinesCount; ++i) 
    {
        totalOutputLength += strlen(*(uniqueLines + i)) + 1; // +1 за новия ред
    }

    char* outputText = new char[totalOutputLength];
    int outputIndex = 0;

    for (int i = 0; i < uniqueLinesCount; ++i) 
    {
        int lineLength = strlen(*(uniqueLines + i));
        strncpy(outputText + outputIndex, *(uniqueLines + i), lineLength);
        outputIndex += lineLength;
        *(outputText + outputIndex) = '\n';
        outputIndex++;
        delete[] *(uniqueLines + i);
    }

    delete[] uniqueLines;
    *(outputText + totalOutputLength - 1) = '\0';
    delete[] funcString.getArray();
    funcString.setData(outputText);
    delete[] outputText;
}

void CountLines::transform(CustomString& funcString)
{
    int count = 0;
    int index = 0;
    while (*(funcString.getArray() + index) != '\0') 
    {
        if (*(funcString.getArray() + index) == '\n') 
        {
            count++;
        }
        index++;
    }
    int* ptr = &count;
    const char* data = reinterpret_cast<const char*>(ptr);
    std::cout << data << std::endl;
    funcString.setData(data);
}

void CountSymbols::transform(CustomString& funcString)
{
    int index = 0;
    while (*(funcString.getArray() + index) != '\0') 
    {
        index++;
    }
    int* ptr = &index;
    const char* data = reinterpret_cast<const char*>(ptr);
    std::cout << data << std::endl;
    funcString.setData(data);
}

