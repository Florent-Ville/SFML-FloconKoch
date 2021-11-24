#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        //Point(Point A, Point B);
        Point(float x, float y);
        virtual ~Point();

        float getX();
        float getY();

        void setX(float x);
        void setY(float y);

    protected:

    private:
    float _x, _y;
};

#endif // POINT_H
