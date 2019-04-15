#ifndef PAINTTABLE_H
#define PAINTTABLE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>




#include "Triangle.h"



class PaintTable : public QWidget
{
    QPainter painter;
    double triangleParamsMas[3];
    double AreaPerimeter[2];
    int    triangleType;

public:

    PaintTable(QWidget*);
    void setParams(double[]);
    void getAreaPerimeter(double*);
    void setTriangleType(int);
protected:

    void paintEvent(QPaintEvent*);

};

#endif // PAINTTABLE_H
