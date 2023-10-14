#pragma once
#include <iostream>
#include "CustomString.h"

class TextOperation 
{
    public:
    virtual void transform(CustomString& funcString) = 0;
    virtual ~TextOperation();
};

class RemoveWord : public TextOperation
{
    private:
    const char* wordToBeRemoved;

    public:
    virtual void transform(CustomString& funcString) override;
    virtual ~RemoveWord();
};

class RemoveLineContainingWord : public TextOperation
{
    private:
    const char* wordToBeRemoved;

    public:
    virtual void transform(CustomString& funcString) override;
    virtual ~RemoveLineContainingWord();
};

class RemoveSymbol : public TextOperation
{
    private:
    char symbolToBeRemoved;

    public:
    virtual void transform(CustomString& funcString) override;
    virtual ~RemoveSymbol();
};

class ReplaceWord : public TextOperation
{
    private:
    const char* toBeReplaced;
    const char* replaceWord;

    public:
    virtual void transform(CustomString& funcString) override;
    virtual ~ReplaceWord();
};

class RemovePunctuation : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
    virtual ~RemovePunctuation();
};

class AddNewLineAfterSentence : public TextOperation
{
    public:
    virtual void transform(CustomString& funcString) override;
    virtual ~AddNewLineAfterSentence();
};

class AddNewLineAfterEachWord : public TextOperation
{
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~AddNewLineAfterEachWord();
};

class AddNewLineEveryKSymbols : public TextOperation
{
    private: 
    int k;
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~AddNewLineEveryKSymbols();
};

class RemoveNewLines : public TextOperation
{
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~RemoveNewLines();
};

class SortAlphabeticallyAllLines : public TextOperation
{
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~SortAlphabeticallyAllLines();
};

class RemoveDuplicateLines : public TextOperation
{
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~RemoveDuplicateLines();
};

class CountLines : public TextOperation
{
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~CountLines();
};

class CountSymbols : public TextOperation
{
    public:
    virtual char* transform(CustomString& funcString) override;
    virtual ~CountSymbols();
};


