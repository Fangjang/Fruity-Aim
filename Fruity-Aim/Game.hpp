#ifndef GAME_H
#define GAME_H

#include "directives.hpp"

class Game
{
private:
	//Game window Variables
	sf::RenderWindow window;
	sf::Event event;

	//Private Methods
	void initWindow();
public:
	//Constructor and Destructor
	Game();
	~Game();

	bool isRunning();
	void update();
	void render();
};

#endif