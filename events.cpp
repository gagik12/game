#include "events.h"
#include "Config.h"
#include <SFML/Graphics.hpp>

void BulletCreate(sf::Sprite player, sf::Sprite Target, float pu)
{



	/*float TargetRotation = player.getRotation();
	Target.setRotation(static_cast<float>(fmod(TargetRotation, 360)));
	float BulletRotation = Target.getRotation();
	if (BulletRotation < 0)
		Target.setRotation(BulletRotation + 360.f);

	float BulletX = Target.getPosition().x;
	float BulletY = Target.getPosition().y;
	for (int n = 1; n == 1;)
	{
		Target.setX(BulletX + pu);
		Target.setY(BulletY + pu);
	}*/
}

void handleEvents(sf::RenderWindow & window, Player &player)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Кнопка закрытия окна
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		// Клавиши управления пакманом
		if (event.type == sf::Event::KeyPressed)
		{

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Стрельба при движении 
			{
				player.isShootRun = true;
			}
			else
			{
				player.isShootRun = false;
			}

			player.isMove = true;
			handlePlayerKeyPress(event.key, player);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			player.isMove = false;
		}
		else if (event.type == sf::Event::MouseButtonPressed)// Стрельба стоя
		{
			if (event.key.code == sf::Mouse::Left)
			{
				player.isShootStand = true;
			}
		}
		else  if (event.type == sf::Event::MouseButtonReleased)// Стрельба стоя
		{
			if (event.key.code == sf::Mouse::Left)
			{
				player.isShootStand = false;
			}
		}
	}
}

int MoveForward(Player &player, float distance, float time)
{
	if (distance <= 10)
	{
		player.direction = Direction::NONE;
		return 1;
	}
	sf::Vector2f speed(player.playerSpeed * time * 5 * player.dX / distance, player.playerSpeed * time * 5 * player.dY / distance);
	if (player.isShootRun)
	{
		MovePlayer(player, time, speed, sf::Vector2f(450, 122), STAND_CURRENT_FRAME);
	}
	else
	{
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	return 0;
}

void DoesNotMove(Player &player, float time)
{
	if (player.isShootStand)
	{
		MovePlayer(player, time, sf::Vector2f(0, 0), sf::Vector2f(300, 122), STAND_CURRENT_FRAME);
	}
	else
	{
		MovePlayer(player, time, sf::Vector2f(0, 0), sf::Vector2f(150, 122), STAND_CURRENT_FRAME);
	}
}

void ShootingWithMove(Player &player, float time, sf::Vector2f speed)
{
	if (player.isShootRun)
	{
		MovePlayer(player, time, speed, sf::Vector2f(450, 122), STAND_CURRENT_FRAME);
	}
	else
	{
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
}

void handlePlayerPress(Player &player, float &time)
{
	float playerSpeed = player.playerSpeed;
	float distance = hypot(player.dX, player.dY);
	switch (player.direction)
	{
	case Direction::UP:
		MoveForward(player, distance, time);
	break;
	case Direction::DOWN:
	{
		sf::Vector2f playerPos(player.dX, player.dY);
		sf::Vector2f speed = -playerSpeed * time * 5 * playerPos / distance;
		MovePlayer(player, time, speed, sf::Vector2f(0, 122), RUN_CURRENT_FRAME);
	}
	break;
	case Direction::NONE:
		DoesNotMove(player, time);
	break;
	case Direction::LEFT:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, 0);
		ShootingWithMove(player, time, speed);
	}
	break;
	case Direction::RIGHT:
	{
		sf::Vector2f speed(playerSpeed * time * 5, 0);
		ShootingWithMove(player, time, speed);
	}
	break;
	case Direction::UP_LEFT:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, -playerSpeed * time * 5);
		ShootingWithMove(player, time, speed);
	}
	break;
	case Direction::UP_RIGHT:
	{
		sf::Vector2f speed(playerSpeed * time * 5, -playerSpeed * time * 5);
		ShootingWithMove(player, time, speed);
	}
	break;
	case Direction::DOWN_RIGHT:
	{
		sf::Vector2f speed(playerSpeed * time * 5, playerSpeed * time * 5);
		ShootingWithMove(player, time, speed);
	}
	break;
	case Direction::DOWN_LEFT:
	{
		sf::Vector2f speed(-playerSpeed * time * 5, playerSpeed * time * 5);
		ShootingWithMove(player, time, speed);
	}
	break;
	}
	if (!player.isMove)
	{
		player.direction = Direction::NONE;
	}
}

bool handlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player)
{
	bool handled = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.direction = Direction::UP_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.direction = Direction::UP_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.direction = Direction::DOWN_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.direction = Direction::DOWN_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.direction = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.direction = Direction::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.direction = Direction::RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.direction = Direction::LEFT;
	}
	else
	{
		player.direction = Direction::NONE;
	}
	return handled;
}