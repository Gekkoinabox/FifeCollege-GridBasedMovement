#pragma once
#include "GridSprite.h"
#include "Grid.h"

class FallingObject : public GridSprite
{
	void CheckBelow();
	void Fall();
};