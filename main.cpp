#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
const Time TIME_PER_FRAME = seconds(1.f / 60.f);

void handleEvents(sf::RenderWindow & window, Player &player)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Кнопка закрытия окна
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		// Клавиши управления пакманом
	    if (event.type == sf::Event::KeyPressed)
		{
			
			if (Mouse::isButtonPressed(Mouse::Left)) // Стрельба при движении 
			{
				player.isShootRun = true;
			}
			else 
			{
				player.isShootRun = false;
			}

			player.isMove = true;
			handlePlayerKeyPress(event.key, player);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			player.isMove = false;
		}
		else if (event.type == Event::MouseButtonPressed)// Стрельба стоя
		{
			if (event.key.code == Mouse::Left)
			{
				player.isShootStand = true;
			}
		}
		else  if (event.type == Event::MouseButtonReleased)// Стрельба стоя
		{
			if (event.key.code == Mouse::Left)
			{
				player.isShootStand = false;
			}
		}
	}
}


void render(sf::RenderWindow & window, Game const& game)
{
    window.clear();
	window.draw(game.map.spriteMap);
	window.draw(game.player.playerSprite);
    window.display();
}

int main(int, char *[])
{
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Window Title");
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
			handleEvents(window, game.player);
			updatePlayer(window, game.player, time);
			render(window, game);
			timeSinceLastUpdate -= TIME_PER_FRAME;
		}
    }
    return 0;
}