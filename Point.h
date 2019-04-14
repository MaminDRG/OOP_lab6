#ifndef POINT_H
#define POINT_H


class Point
{

protected:

double x,y;

public:
    Point(double, double);
    Point();
    void SetPoint(double, double);
    double* GetPoint(double*);
};



#endif // POINT_H
