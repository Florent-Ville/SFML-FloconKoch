#include "Point.h"

Point::Point()
{

}

/*
Point::Point(Point A, Point B)
{
    A.setX(B.getX());

    A.setY(B.getY());

} */

Point::Point(float x, float y)
{
    _x = x;
    _y = y;
}

Point::~Point()
{
    //dtor
}

float Point::getX()
{
    return _x;
}

float Point::getY()
{
    return _y;
}

void Point::setX(float x)
{
    _x = x;
}

void Point::setY(float y)
{
    _y = y;
}
