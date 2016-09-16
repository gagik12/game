#pragma once
#include <SFML/Graphics.hpp>

struct Bullet
{
	sf::Sprite spriteBullet;
};

void InitializeMap(Bullet & bullet, sf::Texture & texturePlayer);