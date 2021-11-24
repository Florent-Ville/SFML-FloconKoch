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


    std::cout << "C.x = " << C.getX();
    std::cout << "C.y = " << C.getY();


    D = ligne.getPointD();

    std::cout << "D.x = " << D.getX();
    std::cout << "D.y = " << D.getY();

    E = ligne.getPointE();

    std::cout << "E.x = " << E.getX();
    std::cout << "E.y = " << E.getY() << std::endl;

  /*  generationRecursive(A, C, niveau - 1, pileListe);
    generationRecursive(C, E, niveau - 1, pileListe);
    generationRecursive(E, D, niveau - 1, pileListe);
    generationRecursive(D, B, niveau - 1, pileListe); */

    generationRecursive(C, A, niveau - 1, pileListe);
    generationRecursive(E, C, niveau - 1, pileListe);
    generationRecursive(D, E, niveau - 1, pileListe);
    generationRecursive(B, D, niveau - 1, pileListe);

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
    Point A(100.f,100.f);
    Point B(500.f,100.f);


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


        //Ligne de Test
        sf::Vertex line[] =
            {
            sf::Vertex(sf::Vector2f(10.f, 10.f)),
            sf::Vertex(sf::Vector2f(150.f, 150.f))
            };

        //window.draw(line, 2, sf::Lines);


        //Graphe Manuelle

    /*    Ligne L(A, B);

        Point Aprime = L.getPointA();
        Point Bprime = L.getPointB();

        float truc = Aprime.getX();
        float truc2 = Aprime.getY();
        float truc3 = Bprime.getX();
        float truc4 = Bprime.getY();

        sf::Vertex line2[] =
            {
            sf::Vertex(sf::Vector2f(truc, truc2)),
            sf::Vertex(sf::Vector2f(truc3, truc4))
            };

        window.draw(line2, 2, sf::Lines);*/

        //std::list<sf::VertexArray> lignesliste;
        //std::list<sf::VertexArray>::iterator iterateur;

        std::stack<sf::VertexArray> lignesliste;


        sf::VertexArray lignes(sf::Lines, 2);
        lignes[0].position = sf::Vector2f(A.getX(), A.getY());
        lignes[1].position = sf::Vector2f(B.getX(), B.getY());

        sf::VertexArray lignes2(sf::Lines, 2);
        lignes2[0].position = sf::Vector2f(200.f, 88.f);
        lignes2[1].position = sf::Vector2f(678.f , 189.f);

        //window.draw(lignes);
       // window.draw(lignes2);

  /*      lignesliste.push(lignes);
        lignesliste.push(lignes2);


        while (!lignesliste.empty())
        {

            window.draw(lignesliste.top());
            lignesliste.pop();
        } */


         //window.draw(lignes);







        generationRecursive(A, B, 1, lignesliste);

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
