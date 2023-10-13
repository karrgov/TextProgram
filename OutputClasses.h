#pragma once
#include <iostream>

class Output 
{
    public:
    virtual void write() = 0;
    virtual ~Output();
};

class FileOutput : public Output
{
    public:
    virtual void write() override;

};

class ConsoleOutput : public Output 
{
    public:
    virtual void write() override;

};