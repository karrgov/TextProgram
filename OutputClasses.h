#pragma once
#include <iostream>
#include "CustomString.h"

class Output 
{
    public:
    virtual void write(CustomString &funcString) = 0;
    virtual ~Output() {}
};

class FileOutput : public Output
{
    private:
    const char* filename;

    public:
    virtual void write(CustomString &funcString) override;

};

class ConsoleOutput : public Output 
{
    private:
    const char* console;
    public:
    virtual void write(CustomString &funcString) override;

};