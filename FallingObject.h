#pragma once
#include "GridSprite.h"
#include "Grid.h"

class FallingObject : public GridSprite
{
public:
	void CheckBelow();
	void Fall();
};