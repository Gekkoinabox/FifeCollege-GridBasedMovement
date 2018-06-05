#pragma once
#include "GridSprite.h"
#include "Grid.h"

class FallingObject : public GridSprite
{
public:
	void Fall();

	void update(const float& _dtAsSeconds) override;
};