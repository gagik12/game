#include <SFML/Graphics.hpp>
#include "game.h"
#include "events.h"
#include "Config.h"
#include <iostream>
#include "view.h"

const Time TIME_PER_FRAME = seconds(1.f / 60.f);

void render(sf::RenderWindow & window, Game const& game)
{
	window.clear();
	window.setView(game.camera.view);
	window.draw(game.map.spriteMap);
	window.draw(game.player.playerSprite);
	window.display();
}

int main(int, char *[])
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window Title");
	Game game;
	InitializeGame(game);

	sf::Clock clock;
	Time timeSinceLastUpdate = Time::Zero;
	while (window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			float time = timeSinceLastUpdate.asSeconds();
			handleEvents(window, game.player);
			updatePlayer(window, game.player, time);
			GetPlayerCoordinateForView(game.camera.view, game.player.playerSprite.getPosition());
			//game.camera.view.setCenter(game.player.playerSprite.getPosition());
			render(window, game);
			timeSinceLastUpdate -= TIME_PER_FRAME;
		}
	}
	return 0;
}