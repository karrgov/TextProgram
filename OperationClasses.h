#pragma once
#include <iostream>
#include "CustomString.h"

class TextOperation 
{
    public:
    virtual CustomString& transform(CustomString& funcString) = 0;
    virtual ~TextOperation();
};

class RemoveWord : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~RemoveWord();
};

class RemoveLineContainingWord : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~RemoveLineContainingWord();
};

class RemoveSymbol : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~RemoveSymbol();
};

class ReplaceWord : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~ReplaceWord();
};

class RemovePunctuation : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~RemovePunctuation();
};

class AddNewLineAfterSentence : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~AddNewLineAfterSentence();
};

class AddNewLineAfterEachWord : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~AddNewLineAfterEachWord();
};

class AddNewLineKSymbols : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~AddNewLineKSymbols();
};

class RemoveNewLines : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~RemoveNewLines();
};

class SortAlphabeticallyAllLines : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~SortAlphabeticallyAllLines();
};

class RemoveDuplicateLines : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~RemoveDuplicateLines();
};

class CountLines : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~CountLines();
};

class CountSymbols : public TextOperation
{
    public:
    virtual CustomString& transform(CustomString& funcString) override;
    virtual ~CountSymbols();
};


