#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "cmath"
#include <iostream>
#include "Point.h"

class Triangle
{
protected:
  double param[3];

public:
    Triangle(double,double,double);
    double side3Find();
    double Area();
    double Perimeter();
    Point* DrawTriangle();
    virtual ~Triangle();
};



#endif // TRIANGLE_H
