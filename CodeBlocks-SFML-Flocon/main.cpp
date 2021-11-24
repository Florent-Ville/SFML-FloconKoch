#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include "Ligne.h"



void generationRecursive(Point A, Point B, int niveau, std::stack<sf::VertexArray>& pileListe)
{
    if(niveau == 0)
    {
        sf::VertexArray lignes(sf::Lines, 2);
        lignes[0].position = sf::Vector2f(A.getX(), A.getY());
        lignes[1].position = sf::Vector2f(B.getX(), B.getY());
        pileListe.push(lignes);

    }else{
    Ligne ligne(A, B);
    Point C, D, E;
    ligne.calculerPoints();
    C = ligne.getPointC();

    //C.setY(-C.getY());


    D = ligne.getPointD();
    //D.setY(-D.getY());


    E = ligne.getPointE();

    //std::cout << "E.x = " << E.getX();
   // std::cout << "E.y = " << E.getY() << std::endl;

  /*  generationRecursive(A, C, niveau - 1, pileListe);
    generationRecursive(C, E, niveau - 1, pileListe);
    generationRecursive(E, D, niveau - 1, pileListe);
    generationRecursive(D, B, niveau - 1, pileListe);*/

    generationRecursive(D, B, niveau - 1, pileListe);
    generationRecursive(E, D, niveau - 1, pileListe);
    generationRecursive(C, E, niveau - 1, pileListe);
    generationRecursive(A, C, niveau - 1, pileListe);

    }
}

int main()
{

    std::list<Ligne*> mesLignes;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("../Ressources/nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();


    //Initialisation
    Point A(100.f,300.f);
    Point B(600.f,300.f);

    //Point C(50.f,70);




    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();


        std::stack<sf::VertexArray> lignesliste;


        int niveau = 3;

        generationRecursive(A, B, niveau, lignesliste);
       // generationRecursive(B, C, niveau, lignesliste);
       // generationRecursive(C, A, niveau, lignesliste);

        while (!lignesliste.empty())
        {
            window.draw(lignesliste.top());
            lignesliste.pop();
        }


        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
