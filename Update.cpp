#include "stdafx.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include "sstream"

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	// Update the grid
	
	m_Grid.update(dtAsSeconds);
	if (!m_Grid.CheckForPlayer())
	{
		setLevel(m_CurrentLevel);
	}
	if (m_Grid.CheckForDiamonds() == 0 && m_Grid.changedExit == false)
	{
		if(m_CurrentLevel == 1)
			m_Grid.SetObject(14, 9, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		if(m_CurrentLevel == 2)
			m_Grid.SetObject(9, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		if (m_CurrentLevel == 3)
			m_Grid.SetObject(11, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		if (m_CurrentLevel == 4)
			m_Grid.SetObject(7, 1, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		if (m_CurrentLevel == 5)
			m_Grid.SetObject(13, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		m_Grid.changedExit = true;
	}
	if (m_Grid.CheckForExit() == 0)
	{
		Engine::setLevel((Engine::m_CurrentLevel) + 1);
		m_Grid.changedExit = false;
	}
	
		

} // end function update()