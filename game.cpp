#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream> 

using namespace sf;

/*struct HeroGame
{
	Texture heroTexture;
	Sprite heroSprite;
	//Vector2f heroPosition();
	
};*/

Texture LoadHeroTexture()
{
	Texture heroTexture;
	heroTexture.loadFromFile("images/hero.png");
	return heroTexture;
}

Sprite SetHeroSprite(Texture const& herotexture)
{
	Sprite heroSprite;
	heroSprite.setTexture(herotexture);
	heroSprite.setTextureRect(IntRect(0, 121, 150, 121));
	heroSprite.setPosition(250, 250);
	return heroSprite;
}

void ProcessEvent(RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

float GetTime(Clock & clock)
{
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	return time / 800;
}

int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "Lesson 7. kychka-pc.ru");

	Texture herotexture = LoadHeroTexture();
	Sprite herosprite = SetHeroSprite(herotexture);

	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;

	float dX = 0;
	float dY = 0;
	Vector2f ();
	float distance = 0;
	while (window.isOpen())
	{
		ProcessEvent(window);

		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)

		float time = GetTime(clock);

		float dX = pos.x - herosprite.getPosition().x;//вектор , колинеарный прямой, которая пересекает спрайт и курсор
		float dY = pos.y - herosprite.getPosition().y;//он же, координата y
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265;//получаем угол в радианах и переводим его в градусы
		
		std::cout << herosprite.getTextureRect().height << std::endl;
		herosprite.setRotation(rotation);//поворачиваем спрайт на эти градусы		
		herosprite.setOrigin(herosprite.getTextureRect().width / 2, herosprite.getTextureRect().height / 2);
	
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::Up))))
		{
			distance = sqrt((pos.x - herosprite.getPosition().x + 150 /2 )*(pos.x - herosprite.getPosition().x + 150 / 2) + (pos.y - herosprite.getPosition().y + 122/2)*(pos.y - herosprite.getPosition().y + 122 / 2));
			CurrentFrame += 0.01*time; 
			if (CurrentFrame > 16)
			{
				CurrentFrame -= 16;
			}
	
			herosprite.setTextureRect(IntRect(0, 122 * int(CurrentFrame), 150, 122)); 
			herosprite.move(0.1*time*(pos.x - herosprite.getPosition().x) / distance, 0.1*time*(pos.y - herosprite.getPosition().y) / distance);
		}


		window.clear(Color::White);
		window.draw(herosprite);
		window.display();
	}

	return 0;
}