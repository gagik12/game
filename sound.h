#pragma once

#include <SFML/Audio.hpp>

struct SoundBuff
{
	sf::SoundBuffer shootBuffer;
	//	sf::Music gameMusic;
	void LoadingFromFileSoundBuffer();
};

struct PlayerSound
{
	sf::Sound shootSound;
};


struct SoundGame
{
	sf::Sound shootSound;
};

void InitializeSound(SoundGame & soundGame, SoundBuff & soundBuffer);