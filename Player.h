#pragma once

#include <SFML/Graphics.hpp>

struct Player
{
	sf::Sprite playerSprite;
};

sf::Sprite initializePlayer(sf::Texture & heroTexture);