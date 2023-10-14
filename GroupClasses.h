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
    CustomString funcString;
    DynamicArray<Input*> inputs;
    DynamicArray<TextOperation*> textOperations;
    DynamicArray<Output*> outputs;

    public:
    Group(CustomString &funcString, DynamicArray<Input*> &inputs, DynamicArray<TextOperation*> &textOperations, DynamicArray<Output*> &outputs);
    void execute();
};

class MultiGroup
{
    private:
    DynamicArray<Group*> multiGroup;

    public:
    MultiGroup(DynamicArray<Group*> multiGroup);
    void execute();

};