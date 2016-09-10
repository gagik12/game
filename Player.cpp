#include "Player.h"
#include <iostream>
#include "math.h"
#include "Config.h"
void InitializePlayer(Player & player, sf::Texture & texturePlayer) 
{
	player.isMove = false;
	player.playerSpeed = PLAYER_SPEED;
	player.playerSprite.setTexture(texturePlayer);
	player.playerSprite.setTextureRect(sf::IntRect(150, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
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
	float playerSpeed = player.playerSpeed;
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

	sf::IntRect textureRect = player.playerSprite.getTextureRect();

	player.playerSprite.setOrigin(textureRect.width / 2, textureRect.height / 2);
	player.dX = pos.x - player.playerSprite.getPosition().x;
	player.dY = pos.y - player.playerSprite.getPosition().y;

	float rotation = (atan2(player.dY, player.dX)) * 180 / 3.14159265;
	player.playerSprite.setRotation(rotation);
	switch (player.direction)
	{
	case Direction::UP:
	{
		float distance = sqrt((player.dX)*(player.dX) + (player.dY)*(player.dY));
		if (distance >= 10)
		{
			sf::Vector2f speed(playerSpeed * time * 5 * player.dX / distance, playerSpeed * time * 5 * player.dY / distance);
			MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
		}
	}
		break;
	case Direction::NONE:
	{
		MovePlayer(player, time, sf::Vector2f(0, 0), sf::Vector2f(150, 122), STAND_CURRENT_FRAME);
	}
	break;

	case Direction::DOWN:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, -playerSpeed * time * 5);
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
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
	}
}

bool handlePackmanKeyPress(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	switch (event.code)
	{
	case sf::Keyboard::Up:
		player.direction = Direction::UP;
		break;
	case sf::Keyboard::Down:
		player.direction = Direction::DOWN;
		break;
	case sf::Keyboard::Left:
		player.direction = Direction::LEFT;
		break;
	case sf::Keyboard::Right:
		player.direction = Direction::RIGHT;
		break;


	default:
		handled = false;
		break;
	}
	return handled;
}

bool handlePackmanKeyRelease(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	
	switch (event.code)
	{
	case sf::Keyboard::Up:
		if (player.direction == Direction::UP)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Down:
		if (player.direction == Direction::DOWN)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Left:
		if (player.direction == Direction::LEFT)
		{
			player.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Right:
		if (player.direction == Direction::RIGHT)
		{
			player.direction = Direction::NONE;
		}
		break;

	default:
		handled = false;
		break;
	}
	return handled;
}