#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "Player.h"

using namespace sf;

struct Game
{
	TextureGame textureGame;
	Player player;
};

void InitializeGame(Game & game);