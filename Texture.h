#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct TextureGame
{
	Texture playerTexture;
	Texture mapTexture;
	Texture bullet;

	void LoadingFromFileTexture();
};