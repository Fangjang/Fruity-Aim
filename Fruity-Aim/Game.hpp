#ifndef GAME_H
#define GAME_H

#include "directives.hpp"

class Game
{
private:
	//Game window Variables
	sf::RenderWindow window;
	sf::Event event;

	//Fonts
	sf::Font font;

	//Sprites
	sf::Sprite sprite;
	
	//Private Methods
	void initWindow();
	void initFonts();
public:
	//Constructor and Destructor
	Game();
	~Game();

	bool isRunning();
	void update();
	void render();
};

#endif