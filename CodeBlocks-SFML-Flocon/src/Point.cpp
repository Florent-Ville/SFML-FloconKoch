#include "Point.h"

Point::Point()
{

}

Point::Point(double x, double y)
{
    _x = x;
    _y = y;
}

Point::~Point()
{
    //dtor
}

double Point::getX()
{
    return _x;
}

double Point::getY()
{
    return _y;
}
