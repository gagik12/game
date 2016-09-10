#pragma once

#include <SFML/Graphics.hpp>

struct Player
{

	sf::Sprite playerSprite;
	float playerSpeed;
	float currentFrame = 0;
	
	float dX = 0;
	float dY = 0;


};

void InitializePlayer(Player & player, sf::Texture & textureGame);
void updatePlayer(sf::RenderWindow & window, Player &player, float & time);