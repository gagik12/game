#include "view.h"

void GetPlayerCoordinateForView(sf::View & view, sf::Vector2f playerPosition)
{
	float tempX = playerPosition.x; 
	float tempY = playerPosition.y;

	if (tempX < 320) tempX = 320;
	if (tempY < 240) tempY = 240;
	if (tempY > 554) tempY = 554;

	view.setCenter(tempX, tempY);

}

void InitializeView(Camera & camera)
{
	camera.view.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
}