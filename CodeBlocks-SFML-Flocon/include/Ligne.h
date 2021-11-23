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
        Point _A;
        Point _B;
        Point _C;
        Point _D;
        Point _E;

        Point getPointA();
        Point getPointB();

        void dessinerLigne();



    protected:

    private:
};

#endif // LIGNE_H
