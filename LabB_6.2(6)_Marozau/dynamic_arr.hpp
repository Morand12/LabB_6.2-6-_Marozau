#pragma once

#include <iostream>
#include "object.hpp"

using namespace std;

class DynamicArray {
private:
    Object** elements;
    int size;
    int capacity;

public:
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;
    virtual ~DynamicArray();

    void addElement(Object* element);
    void removeElement(Object* element);
    void printElements() const;

    virtual void expandCapacity();
    int findIndex(Object* element) const;
    void clear();
};