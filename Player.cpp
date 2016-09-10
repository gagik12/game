#include "Player.h"
#include <iostream>
#include "math.h"
void InitializePlayer(Player & player, sf::Texture & texturePlayer) 
{
	
	player.playerSpeed = 20;
	player.playerSprite.setTexture(texturePlayer);
	player.playerSprite.setTextureRect(sf::IntRect(0, 121, 150, 121));
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float distance = sqrt((player.dX)*(player.dX) + (player.dY)*(player.dY));
		player.currentFrame += playerSpeed * time;
		if (player.currentFrame > 16)
		{
			player.currentFrame -= 16;
		}
		std::cout << player.playerSprite.getOrigin().y;
		player.playerSprite.setTextureRect(sf::IntRect(0, 122 * int(player.currentFrame), 150, 122));
		if (distance >= 10)
		{
			player.playerSprite.move(playerSpeed * time * 5 * player.dX / distance, playerSpeed * time * 5 * player.dY / distance);
		}	
	}
	else
	{
		

	}

}