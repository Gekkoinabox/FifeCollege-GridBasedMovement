#include "stdafx.h"
#include "Player.h"
#include "Grid.h"


// Constructor
Player::Player(sf::Texture& _texture)
	: GridSprite(_texture, GridObject::PLAYER)
{

}

// Handle player movement
bool Player::input(const sf::Event& _event)
{
	// Mark that we have received our input
	m_receivedInput = true;

	if (_event.type == sf::Event::KeyPressed)
	{
		// Handle movement
		if (_event.key.code == sf::Keyboard::Up
			|| _event.key.code == sf::Keyboard::Down
			|| _event.key.code == sf::Keyboard::Left
			|| _event.key.code == sf::Keyboard::Right)
		{
			int targetX = m_gridX;
			int targetY = m_gridY;

			if (_event.key.code == sf::Keyboard::Up)
			{
				--targetY;
			}
			else if (_event.key.code == sf::Keyboard::Down)
			{
				++targetY;
			}
			else if (_event.key.code == sf::Keyboard::Left)
			{
				--targetX;
			}
			else if (_event.key.code == sf::Keyboard::Right)
			{
				++targetX;
			}

			// Get the object currently in our target Cell
			GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);

			// TODO: perform special actions based on content of target cell
			// (if boulder, push)
			// (if boulder and can't push, don't move)
			
			// (if closed exit, don't move)
			// (if open exit, go to next level)

			// NOTE: This will automatically delete whatever GridObject is in the target cell!
			if (targetCellObject == nullptr || targetCellObject->GetType() == GridObject::DIRT)
				m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);

			// (if diamond, collect)
			else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::DIAMOND)
			{
				m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);
				CollectDiamond();
			}

			else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::BOULDER)
			{
				m_grid->MoveObject()
			}

			else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::EXIT && m_DiamondsCollected >= 3)
			{
				//Go to next level
			}

			// Return true since we handled some input
			return true;
		}

	}
}

void Player::CollectDiamond()
{
	//Add 1 to diamonds collected
	++m_DiamondsCollected;
}