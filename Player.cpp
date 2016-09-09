#include "Player.h"
#include <iostream>

sf::Sprite initializePlayer(sf::Texture & heroTexture)
{
	sf::Sprite playerSprite;
	playerSprite.setTexture(heroTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 121, 150, 121));
	playerSprite.setPosition(250, 250);
	return playerSprite;
}