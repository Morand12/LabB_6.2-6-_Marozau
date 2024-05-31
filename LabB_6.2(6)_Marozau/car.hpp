
#include"motorcycle.hpp";
#pragma once
enum class Is_taxi { yes, no, not_identified };

class Car : public Motorcycle
{

public:

    Car(int xmin, int xmax, int ymin, int ymax, double colour, char* number, int size, Is_taxi is_taxi) : Motorcycle(xmin, xmax, ymin, ymax, colour, number, size) {
        if (Is_taxi_validator(is_taxi)) {
            this->is_taxi = is_taxi;
        }
    };
    Car(Car& car) : Motorcycle(car.xmin, car.xmax, car.ymin, car.ymax, car.colour, car.number, car.sizeOfNumber) {
        if (Is_taxi_validator(car.is_taxi))
            this->is_taxi = car.is_taxi;
    }
    Car(Car&& car) : Motorcycle(car.xmin, car.xmax, car.ymin, car.ymax, car.colour, car.number, car.sizeOfNumber) {
        if (Is_taxi_validator(car.is_taxi))
            this->is_taxi = car.is_taxi;
        car.xmin = 0;
        car.xmax = 0;
        car.ymin = 0;
        car.ymax = 0;
        car.colour = 0;
        car.sizeOfNumber = 0;
        car.is_taxi = (Is_taxi)2;
    }
    Car& operator=(const Car& car)
    {
        this->xmax = car.xmax;
        this->xmin = car.xmin;
        this->ymax = car.ymax;
        this->ymin = car.ymin;
        if (colour_validator(car.colour))
            this->colour = car.colour;
        if (number_validator(*car.number)) {
            char* temp = new char[car.sizeOfNumber];
            for (int i = 0; i < car.sizeOfNumber; i++)
            {
                temp[i] = car.number[i];
            }
            this->number = temp;
        }
        if (sizeOfNumber_validator(sizeOfNumber))
            this->sizeOfNumber = sizeOfNumber;
        if (Is_taxi_validator(car.is_taxi))
            this->is_taxi = car.is_taxi;
    }
    //Motorcycle& operator>>(const Motorcycle& moto)
    Car& operator = (Car&& car)
    {
        this->xmax = car.xmax;
        this->xmin = car.xmin;
        this->ymax = car.ymax;
        this->ymin = car.ymin;
        if (colour_validator(car.colour))
            this->colour = car.colour;
        if (number_validator(*car.number)) {
            char* temp = new char[car.sizeOfNumber];
            for (int i = 0; i < car.sizeOfNumber; i++)
            {
                temp[i] = car.number[i];
            }
            this->number = temp;
        }
        if (sizeOfNumber_validator(sizeOfNumber))
            this->sizeOfNumber = sizeOfNumber;
        if (Is_taxi_validator(car.is_taxi))
            this->is_taxi = car.is_taxi;
        car.xmin = 0;
        car.xmax = 0;
        car.ymin = 0;
        car.ymax = 0;
        car.colour = 0;
        car.sizeOfNumber = 0;
        car.is_taxi = (Is_taxi)2;
    }
    ~Car() {
        delete[] number;
        number = nullptr;
        cout << " destr_car ";
    };
    const char* getTextForEnum(Is_taxi is_taxi)
    {
        switch (is_taxi)
        {
        case Is_taxi::yes:
            return "yes";
        case Is_taxi::no:
            return "no";
        case Is_taxi::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }
    virtual const void Print() {
        cout << endl << "Car" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "colour : " << this->colour << " , number : ";
        for (int i = 0; i < this->sizeOfNumber; i++)
        {
            cout << number[i];
        }
        cout << endl;
        cout << "is taxi : " << getTextForEnum(this->is_taxi);
    }

    void set_Is_taxi(Is_taxi is_taxi) {

        this->is_taxi = is_taxi;
    }
    Is_taxi get_Is_taxi(void) {
        return this->is_taxi;
    }
    bool Is_taxi_validator(Is_taxi is_taxi) {
        return ((int)is_taxi >= 0 && (int)is_taxi <= 2);
    }
private:

    Is_taxi is_taxi;



};