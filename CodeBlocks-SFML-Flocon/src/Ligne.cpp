#include "Ligne.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
#include <cmath>

#define SOIXANTE_DEGRES 1.04719755

Ligne::Ligne(Point A, Point B)
{
    _A = A;
    _B = B;
}

Ligne::~Ligne()
{
    //dtor
}

void Ligne::dessinerLigne()
{



}


Point Ligne::getPointA()
{
    return _A;
}

Point Ligne::getPointB()
{
    return _B;
}

Point Ligne::getPointC()
{
    return _C;
}

Point Ligne::getPointD()
{
    return _D;
}

Point Ligne::getPointE()
{
    return _E;
}

float Ligne::distancePoints(Point A, Point B)
{
    return sqrt(pow(A.getX() - B.getX(),2)+ pow(A.getY() - B.getY(),2));
}

float Ligne::anglePoints(Point A, Point B)
{
    Point T(A.getX(),B.getY());
    return acos(distancePoints(A,T) / distancePoints(T,B));
}

void Ligne::calculerPoints()
{
    float distance = distancePoints(_A, _B);
    float angle = anglePoints(_A, _B);

    _C.setX(_A.getX() + distance/3*cos(angle));
    _C.setY(_A.getX() + distance/3*sin(angle));

    _D.setX(_B.getX() - distance/3*cos(angle));
    _D.setY(_B.getX() - distance/3*sin(angle));

    _E.setX(_C.getX() + distance/3*cos(angle + SOIXANTE_DEGRES));
    _E.setY(_C.getX() + distance/3*sin(angle + SOIXANTE_DEGRES));

}
