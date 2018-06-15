#include "stdafx.h"
#include "Engine.h"
#include "GridSprite.h"
#include "Player.h"
#include "FallingObject.h"

using namespace sf;

Engine::Engine()
	: m_Grid(15,15,64.0f,64.0f) // Set your grid size here!
{
	// Get the game screen resolution
	// and creste an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Grid Based Movement Example",
		Style::Titlebar);

	// Initialise the fullscreen view
	m_MainView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// Set the grid position so grid is centered
	sf::Vector2f gridPosition(0,0);
	gridPosition.x = 0.5f*resolution.x -m_Grid.CELL_WIDTH  * 0.5f *(float)m_Grid.GRID_SIZE_X;
	gridPosition.y = 0.5f*resolution.y -m_Grid.CELL_HEIGHT * 0.5f *(float)m_Grid.GRID_SIZE_Y;
	m_Grid.SetPosition(gridPosition);

	// Set up the grid contents
	// NOTE: This could be done based on a file
	// similar to how Thomas Was Late levels were loaded!
	m_CurrentLevel = 1;
	
}

void Engine::run()
{
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		// Make a float from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}

void Engine::setLevel(int currentLevel) //Handing setting up the level
{
	//Check current level
	if (currentLevel == 1)
	{
		// Clear the grid
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{
				
					m_Grid.SetObject(x, y, nullptr, true);
			}
		}
		// create player
		m_Grid.SetObject(0, 0, new Player(TextureHolder::GetTexture("graphics/player_down_01.png")));

		// create exit
		m_Grid.SetObject(14,9, new GridSprite(TextureHolder::GetTexture("graphics/exit_locked.png"), GridObject::EXIT));

		// create diamonds
		m_Grid.SetObject(1, 4, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(7, 3, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(11, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(14, 2, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(8, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));

		// create boulders
		m_Grid.SetObject(1, 5, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(1, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(1, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(7, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(7, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(8, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(8, 3, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(11, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(13, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));

		// Fill the rest of our grid with dirt
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{
				if (m_Grid.GetOjbect(x, y) == nullptr)
					m_Grid.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/dirt.png"), GridObject::DIRT));
			}
		}
	}

	//Check current level
	if (currentLevel == 2)
	{
		// Clear the grid
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{

				m_Grid.SetObject(x, y, nullptr, true);
			}
		}
		// create player
		m_Grid.SetObject(0, 0, new Player(TextureHolder::GetTexture("graphics/player_down_01.png")));

		// create exit
		m_Grid.SetObject(9, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_locked.png"), GridObject::EXIT));

		// create diamonds
		m_Grid.SetObject(1, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(2, 2, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(7, 4, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(9, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(13, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(11, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));

		// create boulders
		m_Grid.SetObject(0, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(0, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(3, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(3, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(10, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(10, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(11, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(13, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(14, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(14, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));

		// Fill the rest of our grid with dirt
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{
				if (m_Grid.GetOjbect(x, y) == nullptr)
					m_Grid.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/dirt.png"), GridObject::DIRT));
			}
		}
	}

	//Check current level
	if (currentLevel == 3)
	{
		// Clear the grid
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{

				m_Grid.SetObject(x, y, nullptr, true);
			}
		}
		// create player
		m_Grid.SetObject(10, 0, new Player(TextureHolder::GetTexture("graphics/player_down_01.png")));

		// create exit
		m_Grid.SetObject(11, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_locked.png"), GridObject::EXIT));

		// create diamonds
		m_Grid.SetObject(0, 3, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(2, 6, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(6, 6, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(8, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(12, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(12, 5, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));

		// create boulders
		m_Grid.SetObject(1, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(2, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(5, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(6, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(6, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(7, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(10, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(10, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));

		// Fill the rest of our grid with dirt
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{
				if (m_Grid.GetOjbect(x, y) == nullptr)
					m_Grid.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/dirt.png"), GridObject::DIRT));
			}
		}
	}

	//Check current level
	if (currentLevel == 4)
	{
		// Clear the grid
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{

				m_Grid.SetObject(x, y, nullptr, true);
			}
		}
		// create player
		m_Grid.SetObject(3, 7, new Player(TextureHolder::GetTexture("graphics/player_down_01.png")));

		// create exit
		m_Grid.SetObject(7, 1, new GridSprite(TextureHolder::GetTexture("graphics/exit_locked.png"), GridObject::EXIT));

		// create diamonds
		m_Grid.SetObject(1, 5, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(1, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(6, 2, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(9, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(13, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(13, 2, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));

		// create boulders
		m_Grid.SetObject(1, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(5, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(5, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(10, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 3, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(14, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));

		// Fill the rest of our grid with dirt
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{
				if (m_Grid.GetOjbect(x, y) == nullptr)
					m_Grid.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/dirt.png"), GridObject::DIRT));
			}
		}
	}
	//Check current level
	if (currentLevel == 5)
	{
		// Clear the grid
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{

				m_Grid.SetObject(x, y, nullptr, true);
			}
		}
		// create player
		m_Grid.SetObject(0, 6,new Player(TextureHolder::GetTexture("graphics/player_down_01.png")));

		// create exit
		m_Grid.SetObject(13, 7, new GridSprite(TextureHolder::GetTexture("graphics/exit_locked.png"), GridObject::EXIT));

		// create diamonds
		m_Grid.SetObject(0, 3, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(0, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(6, 5, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(6, 7, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(7, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(10, 1, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(11, 5, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));
		m_Grid.SetObject(12, 4, new FallingObject(TextureHolder::GetTexture("graphics/diamond.png"), GridObject::DIAMOND));

		// create boulders
		m_Grid.SetObject(0, 4, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(1, 1, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(1, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(6, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(7, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(7, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(11, 2, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(11, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 5, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(12, 7, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));
		m_Grid.SetObject(13, 6, new FallingObject(TextureHolder::GetTexture("graphics/boulder.png"), GridObject::BOULDER));

		// Fill the rest of our grid with dirt
		for (int x = 0; x < m_Grid.GRID_SIZE_X; ++x)
		{
			for (int y = 0; y < m_Grid.GRID_SIZE_Y; ++y)
			{
				if (m_Grid.GetOjbect(x, y) == nullptr)
					m_Grid.SetObject(x, y, new GridSprite(TextureHolder::GetTexture("graphics/dirt.png"), GridObject::DIRT));
			}
		}
	}
	//Check current level
	if (currentLevel == 6)
	{
		//close the game as all levels are finished
		m_Window.close();
	}

	//reset changed exit so if we die after the exit is opened we can still change the exit
	m_Grid.changedExit = false;
	//Set current level
	m_CurrentLevel = currentLevel;
}