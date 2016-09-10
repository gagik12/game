#include "Player.h"
#include <iostream>
#include "Config.h"

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

void handlePackmanPress(Player &player, float &time)
{
	float playerSpeed = player.playerSpeed;

	switch (player.direction)
	{
	case Direction::UP:
	{
		float distance = sqrt((player.dX)*(player.dX) + (player.dY)*(player.dY));
		if (distance >= 10)
		{
			if (player.isShootRun)
			{
				sf::Vector2f speed(playerSpeed * time * 5 * player.dX / distance, playerSpeed * time * 5 * player.dY / distance);
				MovePlayer(player, time, speed, sf::Vector2f(450, 122), STAND_CURRENT_FRAME);
			}
			else
			{
				sf::Vector2f speed(playerSpeed * time * 5 * player.dX / distance, playerSpeed * time * 5 * player.dY / distance);
				MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
			}
		}
	}
	break;
	case Direction::DOWN:
	{
		float distance = sqrt((player.dX)*(player.dX) + (player.dY)*(player.dY));
		if (distance >= 10)
		{
			sf::Vector2f speed(-playerSpeed * time * 5 * player.dX / distance, -playerSpeed * time * 5 * player.dY / distance);
			MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
		}
	}
	break;
	case Direction::NONE:
	{
		if (player.isShootStand)
		{
			MovePlayer(player, time, sf::Vector2f(0, 0), sf::Vector2f(300, 122),  STAND_CURRENT_FRAME);
		}
		else
		{
			MovePlayer(player, time, sf::Vector2f(0, 0), sf::Vector2f(150, 122), STAND_CURRENT_FRAME);
		}
	}
		break;
	case Direction::LEFT:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, 0);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	case Direction::RIGHT:
	{
		sf::Vector2f speed(playerSpeed * time * 5, 0);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	case Direction::UP_LEFT:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, -playerSpeed * time * 5);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	case Direction::UP_RIGHT:
	{
		sf::Vector2f speed(playerSpeed * time * 5, -playerSpeed * time * 5);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	case Direction::DOWN_RIGHT:
	{
		sf::Vector2f speed(playerSpeed * time * 5, playerSpeed * time * 5);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	case Direction::DOWN_LEFT:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, playerSpeed * time * 5);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	}
	if (!player.isMove)
	{
		player.direction = Direction::NONE;
	}
}

void updatePlayer(sf::RenderWindow & window, Player &player, float & time)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

	player.dX = pos.x - player.playerSprite.getPosition().x;
	player.dY = pos.y - player.playerSprite.getPosition().y;

	sf::IntRect textureRect = player.playerSprite.getTextureRect();
	player.playerSprite.setOrigin(textureRect.width / 2, textureRect.height / 2);
	float rotation = (atan2(player.dY, player.dX)) * 180 / 3.14159265;
	player.playerSprite.setRotation(rotation);

	handlePackmanPress(player, time);
}

bool handlePackmanKeyPress(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		player.direction = Direction::UP_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		player.direction = Direction::UP_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		player.direction = Direction::DOWN_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		player.direction = Direction::DOWN_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.direction = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
	{
		player.direction = Direction::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		player.direction = Direction::RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		player.direction = Direction::LEFT;
	}
	else 
	{
		player.direction = Direction::NONE;
	}
	return handled;
}
