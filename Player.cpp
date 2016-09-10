#include "Player.h"
#include <iostream>
#include "math.h"
void InitializePlayer(Player & player, sf::Texture & texturePlayer) 
{
	
	player.playerSpeed = 20;
	player.playerSprite.setTexture(texturePlayer);
	player.playerSprite.setTextureRect(sf::IntRect(150, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
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
		player.currentFrame += playerSpeed * time;
		if (player.currentFrame > 16)
		{
			player.currentFrame -= 16;
		}
		player.playerSprite.setTextureRect(sf::IntRect(0, 122 * int(player.currentFrame), 150, 122));
		if (distance >= 10)
		{
			player.playerSprite.move(playerSpeed * time * 5 * player.dX / distance, playerSpeed * time * 5 * player.dY / distance);
		}
	}
		break;
	case Direction::NONE:
	{
		player.currentFrame += playerSpeed * time;
		if (player.currentFrame > 20)
		{
			player.currentFrame -= 20;
		}
		player.playerSprite.setTextureRect(sf::IntRect(150, 122 * int(player.currentFrame), 150, 122));
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