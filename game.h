#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "Player.h"
#include "map.h"
#include "view.h"
#include "sound.h"

using namespace sf;

struct Game
{
	TextureGame textureGame;
	Player player;
	Map map;
	Camera camera;
	SoundBuff soundBuff;
	SoundGame soundGame;
};

void InitializeGame(Game & game);