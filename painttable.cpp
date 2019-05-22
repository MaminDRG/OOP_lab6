#include "PaintTable.h"
#include "Equilateral_triangle.h"
PaintTable::PaintTable(QWidget* w) : QWidget(w)
{
    double triangleParamsMas[3] = {0,0,0};
    double AreaPerimeter[2] = {0,0};
    int triangleType = 0;
}

void PaintTable::setTriangleType(int type)
{
    triangleType = type;
    if (type < 0 || type > 2) triangleType = 0;
}

void PaintTable::setParams(double Mas[])
{
    triangleParamsMas[0] = Mas[0];
    triangleParamsMas[1] = Mas[1];
    triangleParamsMas[2] = Mas[2];
}

void PaintTable::getAreaPerimeter(double* Mas)
{

    Mas[0] = AreaPerimeter[0];
    Mas[1] = AreaPerimeter[1];
}


void PaintTable::paintEvent(QPaintEvent*)
{
    painter.begin(this);


     QPen pen(Qt::black, 5, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
     painter.setPen(pen);


    painter.drawRect(5, 30, 480, 260);
    painter.setPen(Qt::white);

    double position = 200;

   //QString str1 = ui->LineEdit_side1->text();
    // QString str2 = ui->LineEdit2->text().toDouble();)
   // int x = QString::compare(str1, str2, Qt::CaseInsensitive);

    Triangle* triangle1;
    double temp1 = triangleParamsMas[0];
    double temp2 = triangleParamsMas[1];
    double temp3 = triangleParamsMas[2];
    if (temp1 == 0.0 || temp2 == 0.0 || temp3 == 0.0)
    {
    //painter.drawLine(QPoint(position, position),QPoint(position, position));
        AreaPerimeter[0] = 0;
        AreaPerimeter[1] = 0;
    }

    else

    {
        switch (triangleType)
        {
         case 0:

            triangle1 = new Triangle(temp1,temp2,temp3);
            break;

         case 1:

            triangle1 = new Isosceles_triangle(temp1,temp3);
            break;

         case 2:

            triangle1 = new Equilateral_triangle(temp1);
            break;
        }




        AreaPerimeter[0] = triangle1->Area();
        AreaPerimeter[1] = triangle1->Perimeter();

    Point* triangleParams = triangle1->DrawTriangle();

    Point pointA, pointB, pointC;
    ///////
    double* infoPointA = new double[2];
    double* infoPointB = new double[2];
    double* infoPointC = new double[2];
    ///////

    triangleParams[0].GetPoint(infoPointA);
    triangleParams[1].GetPoint(infoPointB);
    triangleParams[2].GetPoint(infoPointC);



    double Ax = *(infoPointA);
    double Ay = *(infoPointA+1);
    double Bx = (*(infoPointB));
    double By = *(infoPointB+1);
    double Cx = *(infoPointC);
    double Cy = *(infoPointC+1);




   painter.drawLine(QPoint(position - 10*Ax ,position - 10*Ay),QPoint(position - 10*Bx,position - 10*By));
   painter.drawLine(QPoint(position - 10*Bx ,position - 10*By),QPoint(position - 10*Cx,position - 10*Cy));
   painter.drawLine(QPoint(position - 10*Cx ,position - 10*Cy),QPoint(position - 10*Ax,position - 10*Ay));

   delete[] infoPointA;
   delete[] infoPointB;
   delete[] infoPointC;
   delete triangleParams;
    }
    delete triangle1;
    painter.end();
}
