#include "bullet.h"

std::list<Bullet> InitializeBullet(sf::Texture bulletTexture)
{
	std::list<Bullet> bulletList;
	Bullet bullet;
	for (int i = 0; i != 4; ++i)
	{
		bullet.spriteBullet.setTexture(bulletTexture);
		bulletList.push_back(bullet);
	}
	return bulletList;
}

/*void InitializeMap(Map & map, sf::Texture & textureMap)
{
	textureMap.setRepeated(true);
	map.spriteMap.setTexture(textureMap);
	map.spriteMap.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
}*/