#include <iostream>
#include <string>
#include "person.hpp"
#include "bag.hpp"
#include "car.hpp"
#include "motorcycle.hpp"
#include "dynamic_arr.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    DynamicArray objects;
    DynamicArray obj;

    Object* person = new Person(12, 23, 34, 45, (TypeOfPerson)1, (Sex)0, (Baby)2, (Glasses)1, (Beard)0);
    objects.addElement(person);

    Object* bag = new Bag(1, 2, 3, 4, 5);
    objects.addElement(bag);

    char* number = new char[5];
    number[0] = 'x';
    number[1] = '1';
    number[2] = '2';
    number[3] = 'y';
    number[4] = 'b';
    Object* motorcycle = new Motorcycle(1, 3, 12, 6, 3.434567, number, 5);
    objects.addElement(motorcycle);

    Object* car = new Car(45, 76, 98, 1, 5.64738, number, 5, (Is_taxi)1);
    objects.addElement(car);

    Object* object = new Object(8, 3, 6, 4);
    objects.addElement(object);

    objects.printElements();

    /*exhibits.removeElement(coin);*/
    objects.removeElement(person);

    objects.printElements();

    cout << "------------------------------------ ";

    obj = objects;
    objects.clear();
    objects.printElements();
    return 0;
    //expandCapacity() используется в addElement()
    //findIndex() используется в removeElement()
}