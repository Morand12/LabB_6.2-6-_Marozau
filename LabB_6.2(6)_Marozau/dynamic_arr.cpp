#include "dynamic_arr.hpp"

DynamicArray::DynamicArray()
{
    size = 0;
    capacity = 2;
    elements = new Object * [capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    size = other.size;
    capacity = other.capacity;
    elements = new Object * [capacity];
    for (int i = 0; i < size; i++)
    {
        elements[i] = new Object(*other.elements[i]);
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        clear();
        size = other.size;
        capacity = other.capacity;
        elements = new Object * [capacity];
        for (int i = 0; i < size; i++)
        {
            elements[i] = new Object(*other.elements[i]);
        }
    }
    return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept
{
    size = other.size;
    capacity = other.capacity;
    elements = other.elements;
    other.size = 0;
    other.capacity = 0;
    other.elements = nullptr;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept
{
    if (this != &other)
    {
        clear();
        size = other.size;
        capacity = other.capacity;
        elements = other.elements;
        other.size = 0;
        other.capacity = 0;
        other.elements = nullptr;
    }
    return *this;
}

DynamicArray::~DynamicArray()
{
    clear();
    delete[] elements;
}

void DynamicArray::addElement(Object* element)
{
    if (size == capacity)
    {
        expandCapacity();
    }
    elements[size++] = element;
}

void DynamicArray::removeElement(Object* element)
{
    int index = findIndex(element);
    if (index != -1)
    {
        delete elements[index];
        for (int i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
    }
}

void DynamicArray::printElements() const
{
    for (int i = 0; i < size; i++)
    {
        elements[i]->Print();
        cout << endl;
    }
}

void DynamicArray::expandCapacity()
{
    capacity *= 2;
    Object** newElements = new Object * [capacity];
    for (int i = 0; i < size; i++)
    {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

int DynamicArray::findIndex(Object* element) const
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void DynamicArray::clear()
{
    for (int i = 0; i < size; i++)
    {
        delete elements[i];
    }
    size = 0;
}