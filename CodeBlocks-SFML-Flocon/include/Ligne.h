#ifndef LIGNE_H
#define LIGNE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Point.h"


class Ligne
{
    public:
        Ligne(Point A, Point B);
        virtual ~Ligne();

        float distancePoints(Point A, Point B);
        void calculerPoints();
        float anglePoints(Point A, Point B);

        Point getPointA();
        Point getPointB();
        Point getPointC();
        Point getPointD();
        Point getPointE();

        void dessinerLigne();



    protected:

    private:
        Point _A;
        Point _B;
        Point _C;
        Point _D;
        Point _E;
};

#endif // LIGNE_H
