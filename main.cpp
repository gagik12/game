#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
void handleEvents(sf::RenderWindow & window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void render(sf::RenderWindow & window, sf::Sprite &playerSprite)
{
    window.clear();
    window.draw(playerSprite);
    window.display();
}

int main(int, char *[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window Title");
	Game game;
	InitializeGame(game);

    while (window.isOpen())
    {
        handleEvents(window);

        render(window, game.player.playerSprite);
    }

    return 0;
}