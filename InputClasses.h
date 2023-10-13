#pragma once
#include <iostream>

class Input 
{
    public:
    virtual void read() = 0;
    virtual ~Input();
};

class FileInput : public Input 
{
    public:
    virtual void read() override;

};

class ConsoleInput : public Input 
{
    public:
    virtual void read() override;

};