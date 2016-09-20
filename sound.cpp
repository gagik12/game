#include "sound.h"

void SoundBuff::LoadingFromFileSoundBuffer()
{
	shootBuffer.loadFromFile("sound/shoot.ogg");
}

void InitializeSound(SoundGame & soundGame, SoundBuff & soundBuffer)
{
	soundGame.shootSound.setBuffer(soundBuffer.shootBuffer);
}
