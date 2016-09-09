#include "game.h"

using namespace sf;
using namespace std;

void InitializeGame(Game & game) 
{
	game.textureGame.LoadingFromFileTexture();
	InitializePlayer(game.player, game.textureGame.playerTexture);
}