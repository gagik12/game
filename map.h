#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
struct Map
{
	sf::Sprite spriteMap;
};

void InitializeMap(Map & map, sf::Texture & texturePlayer);