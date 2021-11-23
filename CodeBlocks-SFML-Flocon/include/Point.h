#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(double x, double y);
        virtual ~Point();
        double _x, _y;
        double getX();
        double getY();

    protected:

    private:
};

#endif // POINT_H
