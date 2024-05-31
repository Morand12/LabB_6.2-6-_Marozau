
#include"object.hpp";
#pragma once
class Bag : public Object
{
private:

    int secondsAfterMidnight;

public:

    Bag(int xmin, int xmax, int ymin, int ymax, int secondsAfterMidnight) :Object(xmin, xmax, ymin, ymax) {
        if (secondsAfterMidnight_validator(secondsAfterMidnight))
            this->secondsAfterMidnight = secondsAfterMidnight;
    };

    virtual const void Print() {
        cout << endl << "Bag" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "seconds after midnight: " << this->secondsAfterMidnight << endl;
    }

    void set_secondsAfterMidnight(int secondsAfterMidnight) {
        if (secondsAfterMidnight_validator(secondsAfterMidnight))
            this->secondsAfterMidnight = secondsAfterMidnight;
    }
    int get_secondsAfterMidnight() {
        return this->secondsAfterMidnight;
    }
    bool secondsAfterMidnight_validator(int seconds) {
        return seconds > 0;
    }
};