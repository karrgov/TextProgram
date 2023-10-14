#pragma once
#include <iostream>

template <typename T>
class DynamicArray 
{
    private:
    T* array = nullptr;
    int capacity;
    int size;

    protected:
    virtual void expand()
    {
        assert(size == capacity);
        T* data = new T[capacity * 2];
        for (int c = 0; c < capacity; c++)
        {
            *(data + c) = *(array + c);
        }
        delete[] array;
        array = data;
        capacity = capacity * 2;
    }

    public:
    DynamicArray()
    {
        this->capacity = 10;
        this->array = new T[capacity];
        this->size = 0;
    }

    DynamicArray(int capacity)
    {
        this->array = new T[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    DynamicArray(const DynamicArray& other)
    {
        for (int i = 0; i < other.getCapacity(); i++) 
        {
            this->push_back(other[i]);
        }
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (&other != this) 
        {
            delete[] array;
            capacity = 0;
            size = 0;
            for (int i = 0; i < other.getSize(); i++) 
            {
                this->push_back(other[i]);
            }
        }
        return *this;
    }

    T& operator[](int index)
    {
        assert(index >= 0);
        assert(index < size);
        return *(array + index);
    }
    T operator[](int index) const
    {
        assert(index > 0);
        assert(index < size);
        return *(array + index);
    }
    

    ~DynamicArray()
    {
        delete[] array;
    }

    T* getArray()
    {
        return array;
    }

    T* getArray() const
    {
        return array;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void push_back(T newValue)
    {
        if (size >= capacity) 
        {
            expand();
        }
        *(array + size) = newValue;
        size++;
    }

    void pop_back()
    {
        assert(size > 0);
        size--;
    }
};