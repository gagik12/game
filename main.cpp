﻿#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
const Time TIME_PER_FRAME = seconds(1.f / 60.f);
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

void update(sf::RenderWindow & window, float &time, Player & player)
{
	updatePlayer(window, player, time);
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
	//window.setFramerateLimit(60);
	Game game;
	InitializeGame(game);

	sf::Clock clock;
	Time timeSinceLastUpdate = Time::Zero;
    while (window.isOpen())
    {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			float time =  timeSinceLastUpdate.asSeconds();
			handleEvents(window);
			updatePlayer(window, game.player, time);
			render(window, game.player.playerSprite);
			timeSinceLastUpdate -= TIME_PER_FRAME;
		}
    }

    return 0;
}