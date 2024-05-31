
#include <iostream>
#include <string>
#include <stdexcept>
#include "object.hpp";
#pragma once

enum class TypeOfPerson { human, cyclist };
enum class Sex { male, female, not_identified };
enum class Baby { yes, no, not_identified };
enum class Glasses { yes, no, not_identified };
enum class Beard { yes, no, not_identified };

class Person : public Object
{
public:


    Person(int xmin, int xmax, int ymin, int ymax, TypeOfPerson typeOfPerson, Sex sex, Baby baby, Glasses glasses, Beard beard) : Object(xmin, xmax, ymin, ymax) {
        if (TypeOfPerson_validator(typeOfPerson))
            this->typeOfPerson = typeOfPerson;
        if (Sex_validator(sex))
            this->sex = sex;
        if (Baby_validator(baby))
            this->baby = baby;
        if (Glasses_validator(glasses))
            this->glasses = glasses;
        if (Beard_validator(beard))
            this->beard = beard;
    }

    const char* getTextForEnum(TypeOfPerson typeofperson)
    {
        switch (typeofperson)
        {
        case TypeOfPerson::cyclist:
            return "cyclist";
        case TypeOfPerson::human:
            return "human";
        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Sex sex)
    {
        switch (sex)
        {
        case Sex::male:
            return "male";
        case Sex::female:
            return "female";
        case Sex::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Baby baby)
    {
        switch (baby)
        {
        case Baby::yes:
            return "yes";
        case Baby::no:
            return "no";
        case Baby::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Glasses glasses)
    {
        switch (glasses)
        {
        case Glasses::yes:
            return "yes";
        case Glasses::no:
            return "no";
        case Glasses::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Beard beard)
    {
        switch (beard)
        {
        case Beard::yes:
            return "yes";
        case Beard::no:
            return "no";
        case Beard::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    virtual const void Print() {
        cout << endl << "Person" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "type of person : " << getTextForEnum(this->typeOfPerson) << " , sex : " << getTextForEnum(this->sex) << endl;
        cout << "baby : " << getTextForEnum(this->baby) << " , Glasses : " << getTextForEnum(this->glasses) << endl;
        cout << "beard : " << getTextForEnum(this->beard) << endl;
    }

    void set_TypeOfPerson(TypeOfPerson typeOfPerson) {
        if (TypeOfPerson_validator(typeOfPerson))
            this->typeOfPerson = typeOfPerson;
    }
    TypeOfPerson get_TypeOfPerson(void) {
        return this->typeOfPerson;
    }

    void set_Sex(Sex sex) {
        if (Sex_validator(sex))
            this->sex = sex;
    }
    Sex get_Sex(void) {
        return this->sex;
    }

    void set_Baby(Baby baby) {
        if (Baby_validator(baby))
            this->baby = baby;
    }
    Baby get_Baby(void) {
        return this->baby;
    }

    void set_Glasses(Glasses glasses) {
        if (Glasses_validator(glasses))
            this->glasses = glasses;
    }
    Glasses get_Glasses(void) {
        return this->glasses;
    }

    void set_Beard(Beard beard) {
        if (Beard_validator(beard))
            this->beard = beard;
    }
    Beard get_Beard(void) {
        return this->beard;
    }
    bool TypeOfPerson_validator(TypeOfPerson typeOfPerson) {
        return ((int)typeOfPerson >= 0 && (int)typeOfPerson <= 1);
    }
    bool Sex_validator(Sex sex) {
        return((int)sex >= 0 && (int)sex <= 2);
    }
    bool Baby_validator(Baby baby) {
        return((int)baby >= 0 && (int)baby <= 2);
    }
    bool Glasses_validator(Glasses glasses) {
        return((int)glasses >= 0 && (int)glasses <= 2);
    }
    bool Beard_validator(Beard beard) {
        return((int)beard >= 0 && (int)beard <= 2);
    }

private:

    TypeOfPerson typeOfPerson;
    Sex sex;
    Baby baby;
    Glasses glasses;
    Beard beard;

};