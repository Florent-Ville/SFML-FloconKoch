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
    Point T(B.getX(),A.getY());
    return acos(distancePoints(A,T) / distancePoints(A,B));
}

void Ligne::calculerPoints()
{
    float distance = distancePoints(_A, _B);
    float angle = anglePoints(_A, _B);
/*
     Point U(_B.getX() - _A.getX() , _B.getY() - _A.getY()); //Vecteur https://stackoverflow.com/questions/15367165/finding-coordinates-of-koch-curve
     Point V(_A.getY() - _B.getY() , _B.getX() - _A.getX()); //Vecteur

    _C.setX(_A.getX() + ((1/3)* U.getX()));
    _C.setY(_A.getY() + ((1/3)* U.getY()));

    _D.setX(_A.getX() + ((2/3)* U.getX()));
    _D.setY(_A.getY() + ((2/3)* U.getY()));

    _E.setX(_A.getX() + ((1/2)* U.getX()) + ((sqrt(3)/6)*V.getX()));
    _E.setY(_A.getY() + ((1/2)* U.getY()) + ((sqrt(3)/6)*V.getY()));*/


    _C.setX(_A.getX() + distance/3*cos(angle));
    _C.setY(_A.getY() + distance/3*sin(angle));

    _D.setX(_A.getX() + 2*distance/3*cos(angle));
    _D.setY(_A.getY() + 2*distance/3*sin(angle));

    _E.setX(_C.getX() + distance/3*cos(angle + SOIXANTE_DEGRES));
    _E.setY(_C.getY() + distance/3*sin(angle + SOIXANTE_DEGRES));



    /*/Ca où j'ai une ligne parfaitement horizontale/*/
 /*   if(_A.getY() == _B.getY()){

    _C.setX(_A.getX() + distance/3*cos(angle));
    _C.setY(_A.getX() + distance/3*sin(angle));

    _D.setX(_A.getX() + 2*distance/3*cos(angle));
    _D.setY(_A.getX() + 2*distance/3*sin(angle));

    _E.setX(_C.getX() + distance/3*cos(angle + SOIXANTE_DEGRES));
    _E.setY(_C.getX() + distance/3*sin(angle + SOIXANTE_DEGRES));


    }else if(_A.getX() == _B.getX()){



    }else{



    }
*/


}
