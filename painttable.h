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

public:

    PaintTable(QWidget*);
    void setParams(double[]);
    void getAreaPerimeter(double*);
protected:

    void paintEvent(QPaintEvent*);

};

#endif // PAINTTABLE_H
