
#pragma once
#include <iostream>
#include"object.hpp";

class Motorcycle : public Object
{
protected:

    double colour;
    char* number;
    int sizeOfNumber;

public:
    Motorcycle(int xmin, int xmax, int ymin, int ymax, double colour, char* number, int sizeOfNumber) :Object(xmin, xmax, ymin, ymax) {
        if (colour_validator(colour))
            this->colour = colour;
        if (number_validator(*number)) {
            char* temp = new char[sizeOfNumber];
            for (int i = 0; i < sizeOfNumber; i++)
            {
                temp[i] = number[i];
            }
            this->number = temp;
        }

        if (sizeOfNumber_validator(sizeOfNumber))
            this->sizeOfNumber = sizeOfNumber;
    }
    Motorcycle(const Motorcycle& moto) :Object(moto.xmin, moto.xmax, moto.ymin, moto.ymax) {
        if (colour_validator(colour))
            this->colour = moto.colour;
        if (number_validator(*moto.number)) {
            char* temp = new char[moto.sizeOfNumber];
            for (int i = 0; i < moto.sizeOfNumber; i++)
            {
                temp[i] = moto.number[i];
            }
            this->number = temp;
        }
        if (sizeOfNumber_validator(moto.sizeOfNumber))
            this->sizeOfNumber = moto.sizeOfNumber;
    }
    Motorcycle(Motorcycle&& moto) :Object(moto.xmin, moto.xmax, moto.ymin, moto.ymax) {
        if (colour_validator(colour))
            this->colour = moto.colour;
        if (number_validator(*moto.number)) {
            char* temp = new char[moto.sizeOfNumber];
            for (int i = 0; i < moto.sizeOfNumber; i++)
            {
                temp[i] = moto.number[i];
            }
            this->number = temp;
        }
        if (sizeOfNumber_validator(moto.sizeOfNumber))
            this->sizeOfNumber = moto.sizeOfNumber;
        moto.xmin = 0;
        moto.xmax = 0;
        moto.ymin = 0;
        moto.ymax = 0;
        moto.colour = 0;
        moto.sizeOfNumber = 0;
    }
    Motorcycle& operator=(const Motorcycle& moto)
    {
        this->xmax = moto.xmax;
        this->xmin = moto.xmin;
        this->ymax = moto.ymax;
        this->ymin = moto.ymin;
        if (colour_validator(colour))
            this->colour = moto.colour;
        if (number_validator(*moto.number)) {
            char* temp = new char[moto.sizeOfNumber];
            for (int i = 0; i < moto.sizeOfNumber; i++)
            {
                temp[i] = moto.number[i];
            }
            this->number = temp;
        }
        if (sizeOfNumber_validator(moto.sizeOfNumber))
            this->sizeOfNumber = moto.sizeOfNumber;
    }
    //Motorcycle& operator>>(const Motorcycle& moto)
    Motorcycle& operator = (Motorcycle&& moto)
    {
        this->xmax = moto.xmax;
        this->xmin = moto.xmin;
        this->ymax = moto.ymax;
        this->ymin = moto.ymin;
        if (colour_validator(colour))
            this->colour = moto.colour;
        if (number_validator(*moto.number)) {
            char* temp = new char[moto.sizeOfNumber];
            for (int i = 0; i < moto.sizeOfNumber; i++)
            {
                temp[i] = moto.number[i];
            }
            this->number = temp;
        }
        if (sizeOfNumber_validator(moto.sizeOfNumber))
            this->sizeOfNumber = moto.sizeOfNumber;
        moto.xmin = 0;
        moto.xmax = 0;
        moto.ymin = 0;
        moto.ymax = 0;
        moto.colour = 0;
        moto.sizeOfNumber = 0;
    }
    ~Motorcycle() {
        delete[] number;
        number = nullptr;
        cout << " destr_moto ";
    }

    virtual const void Print() {
        cout << endl << "Motorcycle" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "colour : " << this->colour << " , number : ";
        for (int i = 0; i < this->sizeOfNumber; i++)
        {
            cout << number[i];
        }
        cout << endl;
    }

    void set_colour(double colour) {
        if (colour_validator(colour))
            this->colour = colour;
    }
    double get_colour() {
        return this->colour;
    }
    void set_number(char& number) {
        if (number_validator(number))
            this->number = &number;
    }
    char* get_number() {
        return this->number;
    }
    bool sizeOfNumber_validator(int size) {
        return size > 0;
    }
    bool colour_validator(double colour) {
        return colour >= 0;
    }
    bool number_validator(char& number) {
        return strlen(&number) > 0;
    }
};