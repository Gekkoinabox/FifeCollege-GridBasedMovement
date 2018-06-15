#include "stdafx.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include "sstream"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	// Update the grid
	m_Grid.update(dtAsSeconds);
	//Check if the player is dead
	if (!m_Grid.CheckForPlayer())
	{
		//reset the level if they player is indeed dead
		setLevel(m_CurrentLevel);
	}
	//Check the grid if there are no diamonds and we havent changed the exit
	if (m_Grid.CheckForDiamonds() == 0 && m_Grid.changedExit == false)
	{
		//Check level
		if(m_CurrentLevel == 1)
			//Overwrite the exit with the open one
			m_Grid.SetObject(14, 9, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		//Check level
		if(m_CurrentLevel == 2)
			//Overwrite the exit with the open one
			m_Grid.SetObject(9, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		//Check level
		if (m_CurrentLevel == 3)
			//Overwrite the exit with the open one
			m_Grid.SetObject(11, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		//Check level
		if (m_CurrentLevel == 4)
			//Overwrite the exit with the open one
			m_Grid.SetObject(7, 1, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		//Check level
		if (m_CurrentLevel == 5)
			//Overwrite the exit with the open one
			m_Grid.SetObject(13, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		//Since we have changed the exit we will make it true so it does not infinitly create exits
		m_Grid.changedExit = true;
	}
	//Check if there are any exits incase the player has ate it
	if (m_Grid.CheckForExit() == false)
	{
		//Set up the next level
		Engine::setLevel((Engine::m_CurrentLevel) + 1);
	}
} // end function update()