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

	//If the grid space below is empty then move there
	if (targetCellObject == nullptr)
	{
		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
	}
	//If its a player crush them
	else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::PLAYER)
	{
		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
	}
	//If its a boulder and the current object flying through the air is a boulder then make it slide
	else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::BOULDER && isBoulder == true)
	{
		//Check Left to see if its empty
		targetX = m_gridX - 1;
		targetY = m_gridY;
		//Update target
		targetCellObject = m_grid->GetOjbect(targetX, targetY);
		// Get the object currently in our target Cell
		m_grid->GetOjbect(m_gridX, m_gridY);
		//Move left
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

			//Move right
			if (targetCellObject == nullptr)
			{
				m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
			}
			//There is a bug where the boulder constantly moves left and 
			//right while on top of two boulders next to each other, To 
			//solve this i can use a tracker of some sort just like I used
			//on the player to prevent repeat movements
		}
	}
}

void FallingObject::update(const float& _dtAsSeconds) //Update falling object
{
	//Take time away from timer
	framesSinceLastUpdate -= _dtAsSeconds;
	//If we run out of time
	if (framesSinceLastUpdate <= 0)
	{
		//Make everything fall
		Fall();
		//Reset timer
		framesSinceLastUpdate = 1.00f;
	}
}
