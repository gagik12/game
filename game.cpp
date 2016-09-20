#include "game.h"

using namespace sf;
using namespace std;

void InitializeGame(Game & game)
{
	game.textureGame.LoadingFromFileTexture();
	game.soundBuff.LoadingFromFileSoundBuffer();
	InitializeSound(game.soundGame, game.soundBuff);
	InitializePlayer(game.player, game.textureGame, game.soundGame.shootSound);
	InitializeMap(game.map, game.textureGame.mapTexture);
	InitializeView(game.camera);
}