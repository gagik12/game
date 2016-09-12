#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "Player.h"
#include "Texture.h"
#include "map.h"

using namespace sf;

struct Game
{
	TextureGame textureGame;
	Player player;
	Map map;
};

void InitializeGame(Game & game);