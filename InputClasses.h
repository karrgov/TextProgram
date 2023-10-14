#pragma once
#include "CustomString.h"
#include <iostream>

class Input 
{
    public:
    virtual void read(CustomString &funcString) = 0;
    virtual ~Input() {}
};

class FileInput : public Input 
{
    private:
    const char* filename;

    public:
    virtual void read(CustomString &funcString) override;
};

class ConsoleInput : public Input 
{
    private:
    const char* console;

    public:
    virtual void read(CustomString &funcString) override;
    virtual ~ConsoleInput() = default;

};