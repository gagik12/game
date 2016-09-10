#pragma once

#include <SFML/Graphics.hpp>

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT,
};

struct Player
{

	sf::Sprite playerSprite;
	bool isMove;
	float playerSpeed;
	float currentFrame = 0;
	Direction direction;
	float dX = 0;
	float dY = 0;
};

void InitializePlayer(Player & player, sf::Texture & textureGame);
void updatePlayer(sf::RenderWindow & window, Player &player, float & time);
bool handlePackmanKeyPress(const sf::Event::KeyEvent &event, Player &player);
bool handlePackmanKeyRelease(const sf::Event::KeyEvent &event, Player &player);