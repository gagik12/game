#pragma once
#include <SFML/Graphics.hpp>
#include <list>  

struct Bullet
{
	sf::Sprite spriteBullet;
	float angle = 0.5f;
	float damage = 10;
	float speed = 200;

	sf::Vector2f positionBullet;
};

std::list<Bullet> InitializeBullet(sf::Texture bulletTexture);
