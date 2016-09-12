#pragma once
#include "SFML\Graphics.hpp"

struct Map
{
	sf::Sprite spriteMap;
};

void InitializeMap(Map & map, sf::Texture & texturePlayer);