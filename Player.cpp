#include "Player.h"
#include <iostream>

void InitializePlayer(Player & player, sf::Texture & texturePlayer) 
{
	player.playerSprite.setTexture(texturePlayer);
	player.playerSprite.setTextureRect(sf::IntRect(0, 121, 150, 121));
	player.playerSprite.setPosition(250, 250);
}