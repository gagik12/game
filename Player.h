#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "Texture.h"
#include <SFML/Audio.hpp>

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
	std::list<Bullet> bullet;
	Sound shootSound;

	sf::Vector2f playerSpriteSize;
	sf::Vector2f distanceBetweenMouseAndSprite;
	float dX = 0;
	float dY = 0;


};

void InitializePlayer(Player & player, TextureGame & texture, Sound & shootSound);
void MovePlayer(Player &player, float & time, sf::Vector2f & speed, sf::Vector2f & intRect, int currentFrame);
void updatePlayer(sf::RenderWindow & window, Player &player, float & time);
