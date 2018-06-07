#pragma once
#include "GridSprite.h"
#include "Grid.h"

class FallingObject : public GridSprite
{
public:

	FallingObject(sf::Texture _texture, GridObject::Type _type) : GridSprite(_texture, _type){}
	void Fall();

	void update(const float& _dtAsSeconds) override;
};