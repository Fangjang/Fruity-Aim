#include "Game.hpp"

///
/// PRIVATE METHODS
/// 
void Game::initWindow()
{
	//Create a 1080p fullscrenn window
	window.create(sf::VideoMode(800, 600), "Fruity Aim", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
}

/// 
/// PUBLIC METHODS
/// 
//Constructor and Destructor
Game::Game()
{
	initWindow();
}
//Destructor
Game::~Game()
{

}

//Returns the status of the window
bool Game::isRunning()
{
	return window.isOpen();
}

//Updates the game
void Game::update()
{
	//Event polling
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

//Renders the game
void Game::render()
{
	window.clear(sf::Color::Black);
	window.display();
}
