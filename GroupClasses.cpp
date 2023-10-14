#include "DynamicArray.h"
#include "CustomString.h"
#include "InputClasses.h"
#include "OperationClasses.h"
#include "OutputClasses.h"
#include "GroupClasses.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

Group::Group(CustomString &funcString, DynamicArray<Input*> &inputs, DynamicArray<TextOperation*> &textOperations, DynamicArray<Output*> &outputs)
{
    funcString = funcString;
    inputs = inputs;
    textOperations = textOperations;
    outputs = outputs;
}

void Group::execute()
{
    for (int i = 0; i < inputs.getSize(); i++)
    {
        (*(*(inputs.getArray() + i))).read(funcString);
    } 

    for (int i = 0; i < textOperations.getSize(); i++)
    {
        (*(textOperations.getArray() + i))->transform(funcString);
    } 

    for (int i = 0; i < outputs.getSize(); i++)
    {
        (*(outputs.getArray() + i))->write(funcString);
    } 
}

MultiGroup::MultiGroup(DynamicArray<Group*> multiGroup)
{
    multiGroup = multiGroup;
}

void MultiGroup::execute()
{
    for (int i = 0; i < multiGroup.getSize(); i++)
    {
        (*(multiGroup.getArray() + i))->Group::execute();
    }
    
}