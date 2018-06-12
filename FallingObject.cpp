#include "stdafx.h"
#include "FallingObject.h"
#include "Grid.h"
#include "Engine.h"
#include "GridSprite.h"

void FallingObject::Fall()
{
	//sf::Clock clock1;
	//sf::Time elapsed = clock1.getElapsedTime();
	//if (elapsed.asSeconds() == 1)
	//{
		int targetX = m_gridX;
		int targetY = m_gridY + 1;

		// Get the object currently in our target Cell
		GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);
		m_grid->GetOjbect(m_gridX, m_gridY);

		//If there is nothing in the target cell
		if (targetCellObject == nullptr)
		{
			//Move into that space
			m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);
		}
		//If the player is in the target cell
		else if (targetCellObject->GetType() == GridObject::PLAYER)
		{
			//Move into that slot and kill the player
			m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);
			//TODO: GAMEOVER SCREEN
		}
		//clock1.restart();
		
	//}

}

void FallingObject::update(const float& _dtAsSeconds)
{
	Fall();
}
