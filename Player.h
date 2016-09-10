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
	bool isKilled;
	bool isShootStand;
	bool isShootRun;
	float playerSpeed;
	float currentFrame = 0;
	Direction direction;
	sf::Vector2f playerSpriteSize;
	float dX = 0;
	float dY = 0;


};

void InitializePlayer(Player & player, sf::Texture & textureGame);
void MovePlayer(Player &player, float & time, sf::Vector2f & speed, sf::Vector2f & intRect, int currentFrame);
void updatePlayer(sf::RenderWindow & window, Player &player, float & time);
bool handlePackmanKeyPress(const sf::Event::KeyEvent &event, Player &player);
void handlePackmanPress(Player &player, float &time);