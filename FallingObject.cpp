#include "stdafx.h"
#include "FallingObject.h"
#include "Grid.h"
#include "Engine.h"
#include "GridSprite.h"

void FallingObject::Fall()
{
	sf::Clock clock1;
	sf::Time dt = clock1.restart();
	
	m_TimeRemaining -= dt.asSeconds();

	if (m_TimeRemaining <= 0.0f)
	{
		int targetX = m_gridX;
		int targetY = m_gridY + 1;

		// Get the object currently in our target Cell
		GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);
		m_grid->GetOjbect(m_gridX, m_gridY);

		if (targetCellObject == nullptr)
		{
			m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
		}
		else if (targetCellObject->GetType() == GridObject::PLAYER)
		{
			m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY);
			//TODO: GAMEOVER SCREEN
		}
		m_TimeRemaining = 1.0f;
		
	}

	// TODO: perform special actions based on content of target cell
}

void FallingObject::update(const float& _dtAsSeconds)
{
	Fall();
}
