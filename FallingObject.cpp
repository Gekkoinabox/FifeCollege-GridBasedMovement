#include "stdafx.h"
#include "FallingObject.h"
#include "Grid.h"
#include "Engine.h"
#include "GridSprite.h"

void FallingObject::Fall()
{

	//Check Below
	int targetX = m_gridX;
	int targetY = m_gridY;

	if (m_grid->GetOjbect(targetX, targetY)->GetType() == GridObject::BOULDER)
		isBoulder = true;

	targetX = m_gridX;
	targetY = m_gridY + 1;

	// Get the object currently in our target Cell
	GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);
	m_grid->GetOjbect(m_gridX, m_gridY);

	if (targetCellObject == nullptr)
	{
		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
	}
	else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::PLAYER)
	{
		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
		//TODO: GAMEOVER SCREEN
	}
	else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::BOULDER && isBoulder == true)
	{
		//Check Left to see if its empty
		targetX = m_gridX - 1;
		targetY = m_gridY;
		//Update target
		targetCellObject = m_grid->GetOjbect(targetX, targetY);
		// Get the object currently in our target Cell
		m_grid->GetOjbect(m_gridX, m_gridY);

		if (targetCellObject == nullptr)
		{
			m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
		}
		else if (targetCellObject != nullptr)
		{
			//Check right
			targetX = m_gridX + 1;
			targetY = m_gridY;

			// Get the object currently in our target Cell
			targetCellObject = m_grid->GetOjbect(targetX, targetY);
			m_grid->GetOjbect(m_gridX, m_gridY);

			if (targetCellObject == nullptr)
			{
				m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
			}
		}
	}


	// TODO: perform special actions based on content of target cell
}

void FallingObject::update(const float& _dtAsSeconds)
{
	framesSinceLastUpdate -= _dtAsSeconds;
	if (framesSinceLastUpdate <= 0)
	{
		Fall();
		framesSinceLastUpdate = 1.00f;
	}
}
