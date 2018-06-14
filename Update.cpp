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
		m_Grid.SetObject(9, 9, new GridSprite(TextureHolder::GetTexture("graphics/exit_open.png"), GridObject::EXIT));
		m_Grid.changedExit = true;
	}
		

} // end function update()