#pragma once
#include <iostream>
#include "CustomString.h"

class TextOperation 
{
    public:
    virtual void transform(CustomString& funcString) = 0;
    virtual ~TextOperation() {}
};

class RemoveWord : public TextOperation
{
    private:
    const char* wordToBeRemoved;

    public:
    RemoveWord(const char* word) : wordToBeRemoved(word) {}
    virtual void transform(CustomString& funcString) override;
};

class RemoveLineContainingWord : public TextOperation
{
    private:
    const char* wordToBeRemoved;

    public:
    RemoveLineContainingWord(const char* word) : wordToBeRemoved(word) {}
    virtual void transform(CustomString& funcString) override;
};

class RemoveSymbol : public TextOperation
{
    private:
    char symbolToBeRemoved;

    public:
    RemoveSymbol(char symbol) : symbolToBeRemoved(symbol) {}
    virtual void transform(CustomString& funcString) override;
};

class ReplaceWord : public TextOperation
{
    private:
    const char* toBeReplaced;
    const char* replaceWord;

    public:
    ReplaceWord(const char* word1, const char* word2) : toBeReplaced(word1), replaceWord(word2) {}
    virtual void transform(CustomString& funcString) override;
};

class RemovePunctuation : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class AddNewLineAfterSentence : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class AddNewLineAfterEachWord : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class AddNewLineEveryKSymbols : public TextOperation
{
    private: 
    int k;

    public:
    AddNewLineEveryKSymbols(int m) : k(m) {}
    virtual void transform(CustomString& funcString) override;
};

class RemoveNewLines : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class SortAlphabeticallyAllLines : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class RemoveDuplicateLines : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class CountLines : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};

class CountSymbols : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
};


