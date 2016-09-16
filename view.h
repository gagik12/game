#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"

struct Camera
{
	sf::View view;
};

void InitializeView(Camera & camera);
void GetPlayerCoordinateForView(sf::View & view, sf::Vector2f playerPosition);