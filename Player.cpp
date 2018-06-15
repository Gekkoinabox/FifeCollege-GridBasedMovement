#include "stdafx.h"
#include "Player.h"
#include "Grid.h"
#include "Engine.h"
#include "GridSprite.h"


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
				keyLastPressed = "Up";
			}
			else if (_event.key.code == sf::Keyboard::Down)
			{
				++targetY;
				keyLastPressed = "Down";
			}
			else if (_event.key.code == sf::Keyboard::Left)
			{
				--targetX;
				keyLastPressed = "Left";
			}
			else if (_event.key.code == sf::Keyboard::Right)
			{
				++targetX;
				keyLastPressed = "Right";
			}

			// Get the object currently in our target Cell
			GridObject* targetCellObject = m_grid->GetOjbect(targetX, targetY);

			// TODO: perform special actions based on content of target cell
			
			// (if boulder and can't push, don't move)
			
			// (if closed exit, don't move)
			// (if open exit, go to next level)

			// NOTE: This will automatically delete whatever GridObject is in the target cell!
			if (targetCellObject == nullptr || targetCellObject->GetType() == GridObject::DIRT)
				m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);

			//Check if target is a diamond
			else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::DIAMOND)
			{
				//Destroy diamond and move player to the grid
				m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);
				//add 1 diamond to the collection
				CollectDiamond();
			}
			////Check if the target is the boulder
			//else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::BOULDER)
			//{
			//	//Check to see if the player is going left
			//	if (keyLastPressed == "Left" && m_grid->GetOjbect(targetX - 2, targetY) == nullptr && (targetX - 2) >= -1)
			//	{
			//		//Get boulder grid object
			//		m_grid->GetOjbect(targetX -1, targetY);
			//		//Move boulder to the right 1 grid space
			//		m_grid->MoveObject(m_gridX - 1, m_gridY, targetX - 1, targetY, false);
			//		//Get Player grid Object
			//		m_grid->GetOjbect(targetX, targetY);
			//		//Move Player to the right 1 grid space
			//		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, false);
			//	
			//	}
			//	//Check to see if the player is going right
			//	if (keyLastPressed == "Right" && m_grid->GetOjbect(targetX + 2, targetY) == nullptr && (targetX + 2) <= 15)
			//	{
			//		//Get boulder grid object
			//		m_grid->GetOjbect(targetX + 1, targetY);
			//		//Move boulder to the right 1 grid space
			//		m_grid->MoveObject(m_gridX+1, m_gridY, targetX+1, targetY, false);
			//		//Get Player grid Object
			//		m_grid->GetOjbect(targetX, targetY);
			//		//Move Player to the right 1 grid space
			//		m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, false);
			//	}
			//}

			else if (targetCellObject != nullptr && targetCellObject->GetType() == GridObject::EXIT)
			{
				if (m_grid->CheckForDiamonds() == 0)
				{
					m_grid->MoveObject(m_gridX, m_gridY, targetX, targetY, true);
				}

				//TODO: CHANGELEVEL
				newLevelNeeded = true;
				
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