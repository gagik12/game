#include "game.h"

using namespace sf;
using namespace std;

void InitializeGame(Game & game) 
{
	game.textureGame.LoadingFromFileTexture();
	game.player.playerSprite = initializePlayer(game.textureGame.playerTexture);
	//InitializePlayer(*game.player, game.textureGame);
}