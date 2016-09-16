#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

void handleEvents(sf::RenderWindow & window, Player &player);
bool handlePlayerKeyPress(const sf::Event::KeyEvent &event, Player &player);
void handlePlayerPress(Player &player, float &time);