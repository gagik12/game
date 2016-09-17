#include "map.h"
using namespace sf;

void InitializeMap(Map & map, sf::Texture & textureMap)
{
	textureMap.setRepeated(true);
	map.spriteMap.setTexture(textureMap);
	map.spriteMap.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
}