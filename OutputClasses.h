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
    FileOutput(const char* name) : filename(name) {}
    virtual void write(CustomString &funcString) override;

};

class ConsoleOutput : public Output 
{
    public:
    virtual void write(CustomString &funcString) override;

};