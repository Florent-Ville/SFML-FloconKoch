#include "Ligne.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
#include <cmath>

#define SOIXANTE_DEGRES 1.0471975512

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
    Point T(B.getX(),A.getY());
    return acos(distancePoints(A,T) / distancePoints(A,B));
}

void Ligne::calculerPoints()
{
    float distance = distancePoints(_A, _B);
    float angle = anglePoints(_A, _B);
/*

    if(_A.getY() == _B.getY()){
        _C.setX(_A.getX() + distance/3*cos(angle));
        _C.setY(_A.getY() + distance/3*sin(angle));

        _D.setX(_A.getX() + 2*distance/3*cos(angle));
        _D.setY(_A.getY() + 2*distance/3*sin(angle));

        _E.setX(_C.getX() + distance/3*cos(angle + SOIXANTE_DEGRES));
        _E.setY(_C.getY() + distance/3*sin(angle + SOIXANTE_DEGRES));

     }else if(_A.getX() < _B.getX()){
        _C.setX(_A.getX() + (_A.getX() + distance)/3);
        _C.setY(_A.getY() + (_A.getY() + distance)/3);

        _D.setX(_A.getX() + 2*(_A.getX() + distance)/3);
        _D.setY(_A.getY() + 2*(_A.getY() + distance)/3);

        _E.setX(_C.getX() + distance/3*cos(angle + SOIXANTE_DEGRES));
        _E.setY(_C.getY() + distance/3*sin(angle + SOIXANTE_DEGRES));
    }
*/

        _C.setX(_A.getX() + (_B.getX() - _A.getX())/3);
        _C.setY(_A.getY() + (_B.getY() - _A.getY())/3);

        _D.setX(_A.getX() + 2*(_B.getX() - _A.getX())/3);
        _D.setY(_A.getY() + 2*(_B.getY() - _A.getY())/3);


        float dX = _D.getX() - _C.getX();
        float dY = _D.getY() - _C.getY();

        _E.setX((cos(SOIXANTE_DEGRES) * dX + sin(SOIXANTE_DEGRES) * dY) + _C.getX());
        _E.setY((-sin(SOIXANTE_DEGRES) * dX + cos(SOIXANTE_DEGRES) * dY) + _C.getY());

        //_E.setX(_C.getX() + distance/3*cos(angle + SOIXANTE_DEGRES));
        //_E.setY(_C.getY() + distance/3*sin(angle + SOIXANTE_DEGRES));



}
