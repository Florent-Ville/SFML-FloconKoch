#include "Ligne.h"
#include "Point.h"
#include <SFML/Graphics.hpp>

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
