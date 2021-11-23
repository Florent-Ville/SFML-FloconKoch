#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>
#include "Ligne.h"

int main()
{

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("../Ressources/nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();

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

        window.draw(line, 2, sf::Lines);

        Point A(10,10);
        Point B(10, 100);

        Ligne L(A, B);

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

        window.draw(line2, 2, sf::Lines);




        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
