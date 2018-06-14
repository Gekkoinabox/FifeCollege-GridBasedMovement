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

} // end function update()