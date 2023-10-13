#pragma once
#include "DynamicArray.h"
#include "CustomString.h"
#include "InputClasses.h"
#include "OutputClasses.h"
#include "OperationClasses.h"

#include <iostream>

class Group
{
    private:
    CustomString string;
    DynamicArray<Input*> inputs;
    DynamicArray<TextOperation*> textOperations;
    DynamicArray<Output*> outputs;

    public:
    Group();
    void execute();
};

class MultiGroup
{
    private:
    DynamicArray<Group*> multiGroup;

    public:
    MultiGroup();
    void execute();

};