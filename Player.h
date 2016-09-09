#pragma once

#include <SFML/Graphics.hpp>

struct Player
{
	sf::Sprite playerSprite;
};

void InitializePlayer(Player & player, sf::Texture & textureGame);