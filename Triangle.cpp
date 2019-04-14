#include "Triangle.h"

Triangle::Triangle(double side1, double side2, double angle12)
{
    param[0] = side1;
    param[1] = side2;
    param[2] = angle12;
}


double Triangle::side3Find()
{
    ///////
    double side3;
    Point pointA, pointB, pointC;
    ///////
    double* infoPointA = new double[2];
    ///////

    pointA.GetPoint(infoPointA);
    pointB.SetPoint(*(infoPointA) - param[0], *(infoPointA+1));


    double Ax = (*(infoPointA));
    double Ay = (*(infoPointA+1));
    double Bx = (*(infoPointA) - param[0]);
    double By = (*(infoPointA+1));
    double AB = param[0];
    double BC = param[1];
    //angle abc in degrees. it needs to be because of not understanding how to check if cos == 0 or not
    //for example: if (angle == 90 degrees) cos = -1.03634e-13 not 0.0
    double ABC = param[2];
    //angle abc in radians
    double ABCrad = param[2] * 3.14159265359 / 180;
    double alpha = Bx - Ax;
    double betta = By - Ay;
    double gamma = AB*BC*cos(ABCrad);
    double omega = BC*BC;
    double y2 = 0;

        if (ABC == 90) gamma = 0;

        if (gamma == 0)
        {
            y2 = sqrtl((omega*alpha*alpha)/(1+alpha*alpha));
        }

            else
        {
            double determ = ((2*gamma*betta)*(2*gamma*betta) - 4*(1+alpha*alpha)*(gamma*gamma-omega*alpha*alpha));
           double temp1 = ((2*gamma*betta) - sqrtl(determ))/(2*(1+alpha*alpha));
           double temp2 = ((2*gamma*betta) - sqrtl(determ))/(2*(1+alpha*alpha));
            y2 = std::max(temp1,temp2);
        }




    double Cy = y2+By;
    double Cx = Bx - (gamma-betta*(By-Cy))/alpha;

    /////
    if ( betta == 0)
    {
        Cx = Bx - gamma/alpha;
    }
    ////

    // recalculation
    if ((Cx-Bx) != 0) Cy = sqrtl(omega-((Cx-Bx)*(Cx-Bx)))+By;
    else Cy = sqrtl(omega)+By;



    pointC.SetPoint(Cx,Cy);
    double* infoPointC = new double[2];
    ///////

    pointC.GetPoint(infoPointC);

    side3 = sqrtl( ( ( (*(infoPointC)) - (*(infoPointA)) ) * ( (*(infoPointC)) - (*(infoPointA)) ) ) +( ( (*(infoPointC+1)) - (*(infoPointA+1)) ) * ( (*(infoPointC+1)) - (*(infoPointA+1)) ) ) );


    delete [] infoPointA;
    delete [] infoPointC;
    return side3;
}

double Triangle::Perimeter()
{

    double side3 = this->side3Find();
    return side3 + param[0] + param[1];
}

double Triangle::Area()
{
    double side3 = this->side3Find();
    double halfOfPerim = this->Perimeter()/2;
    double Area = sqrtl(halfOfPerim* (halfOfPerim - param[0]) * (halfOfPerim - param[1]) * (halfOfPerim - side3));
    return Area;
}
Point* Triangle::DrawTriangle()
{
    ///////
    double side3;
    Point pointA, pointB, pointC;
    ///////
    double* infoPointA = new double[2];
    ///////

    pointA.GetPoint(infoPointA);
    pointB.SetPoint(*(infoPointA) - param[0], *(infoPointA+1));


    double Ax = (*(infoPointA));
    double Ay = (*(infoPointA+1));
    double Bx = (*(infoPointA) - param[0]);
    double By = (*(infoPointA+1));
    double AB = param[0];
    double BC = param[1];
    //angle abc in degrees. it needs to be because of not understanding how to check if cos == 0 or not
    //for example: if (angle == 90 degrees) cos = -1.03634e-13 not 0.0
    double ABC = param[2];
    //angle abc in radians
    double ABCrad = param[2] * 3.14159265359 / 180;
    double alpha = Bx - Ax;
    double betta = By - Ay;
    double gamma = AB*BC*cos(ABCrad);
    double omega = BC*BC;
    double y2 = 0;

        if (ABC == 90) gamma = 0;

        if (gamma == 0)
        {
            y2 = sqrtl((omega*alpha*alpha)/(1+alpha*alpha));
        }

            else
        {
            double determ = ((2*gamma*betta)*(2*gamma*betta) - 4*(1+alpha*alpha)*(gamma*gamma-omega*alpha*alpha));
           double temp1 = ((2*gamma*betta) - sqrtl(determ))/(2*(1+alpha*alpha));
           double temp2 = ((2*gamma*betta) - sqrtl(determ))/(2*(1+alpha*alpha));
            y2 = std::max(temp1,temp2);
        }




    double Cy = y2+By;
    double Cx = Bx - (gamma-betta*(By-Cy))/alpha;

    /////
    if ( betta == 0)
    {
        Cx = Bx - gamma/alpha;
    }
    ////

    // recalculation
    if ((Cx-Bx) != 0) Cy = sqrtl(omega-((Cx-Bx)*(Cx-Bx)))+By;
    else Cy = sqrtl(omega)+By;



    pointC.SetPoint(Cx,Cy);
    double* infoPointC = new double[2];
    ///////

    pointC.GetPoint(infoPointC);

    side3 = sqrtl( ( ( (*(infoPointC)) - (*(infoPointA)) ) * ( (*(infoPointC)) - (*(infoPointA)) ) ) +( ( (*(infoPointC+1)) - (*(infoPointA+1)) ) * ( (*(infoPointC+1)) - (*(infoPointA+1)) ) ) );

    Point* Points_of_triangle = new Point[3];
    (*Points_of_triangle).SetPoint(Ax,Ay);
    (*(Points_of_triangle+1)).SetPoint(Bx,By);
    (*(Points_of_triangle+2)).SetPoint(Cx,Cy);

    delete [] infoPointA;
    delete [] infoPointC;
   return Points_of_triangle;
}

Triangle::~Triangle()
{}
