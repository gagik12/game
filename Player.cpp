#include "Player.h"
#include "events.h"
#include "Config.h"
#include <cmath>
#include <iostream>

void InitializePlayer(Player & player, sf::Texture & texturePlayer)
{
	player.isMove = false;
	player.isShootStand = false;
	player.isShootRun = false;
	player.playerSpeed = PLAYER_SPEED;
	player.playerSprite.setTexture(texturePlayer);
	player.playerSprite.setTextureRect(sf::IntRect(150, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
	player.playerSpriteSize = sf::Vector2f(150, 121);
}

void ChangeFrame(Player &player, float & time, sf::Vector2i & intRect, int currentFrame)
{
	player.currentFrame += PLAYER_SPEED * time;
	if (player.currentFrame > currentFrame)
	{
		player.currentFrame -= currentFrame;
	}
	player.playerSprite.setTextureRect(sf::IntRect(intRect.x, intRect.y * int(player.currentFrame), 150, 122));
}

void MovePlayer(Player &player, float & time, sf::Vector2f & speed, sf::Vector2f & intRect, int currentFrame)
{
	player.currentFrame += PLAYER_SPEED * time;
	if (player.currentFrame > currentFrame)
	{
		player.currentFrame -= currentFrame;
	}
	player.playerSprite.setTextureRect(sf::IntRect(intRect.x, intRect.y * int(player.currentFrame), 150, 122));
	player.playerSprite.move(speed);
}

void updatePlayer(sf::RenderWindow & window, Player &player, float & time)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

	player.dX = pos.x - player.playerSprite.getPosition().x;
	player.dY = pos.y - player.playerSprite.getPosition().y;

	sf::IntRect textureRect = player.playerSprite.getTextureRect();
	player.playerSprite.setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);
	double rotation = (atan2(player.dY, player.dX)) * 180 / 3.14159265;
	player.playerSprite.setRotation(static_cast<float>(rotation));

	handlePlayerPress(player, time);
}

