#include "stdafx.h"
#include "FallingObject.h"
#include "Grid.h"
#include "Engine.h"
#include "GridSprite.h"

void FallingObject::CheckBelow()
{
	int targetX = m_gridX;
	int targetY = m_gridY-1;

	// Get the object currently in our target Cell
	GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);

	if (targetCellObject ==nullptr)
	{
		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
	}

	// TODO: perform special actions based on content of target cell
}

void FallingObject::Fall()
{
	
}