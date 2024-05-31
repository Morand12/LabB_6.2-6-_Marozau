#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Object
{
private:

protected:
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;

public:
    Object(int xmin, int xmax, int ymin, int ymax) {
        this->xmin = xmin;
        this->xmax = xmax;
        this->ymin = ymin;
        this->ymax = ymax;
    }
    virtual const void Print() {
        cout << endl << "Object" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
    }
};