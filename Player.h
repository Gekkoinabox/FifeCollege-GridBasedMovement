#pragma once

#include "GridSprite.h"
#include <string>

// Player class
// A GridSprite which can move around
class Player : public GridSprite
{
public:
	// Constructor
	Player(sf::Texture& _texture);
	std::string keyLastPressed;

	// Game Object Functions
	bool input(const sf::Event& _event) override;

};