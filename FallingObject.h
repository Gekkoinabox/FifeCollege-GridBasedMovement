#pragma once
#include "GridSprite.h"
#include "Grid.h"

class FallingObject : public GridSprite
{
private:
	float m_TimeRemaining = 1.0f;
	float m_CurrentTime = 0.0f;

public:
	FallingObject(sf::Texture& _texture, GridObject::Type _type) : GridSprite(_texture, _type){}
	void Fall();
	void update(const float& _dtAsSeconds) override;
};