#ifndef GAME_H
#define GAME_H

#include "directives.hpp"
#include "menuAnimator.hpp"
#include "GamePlay.hpp"

class Game
{
private:
	//Game window Variables
	sf::RenderWindow window;
	sf::Event event;

	//Program State
	enum class GameState { MENU, GAMEPLAY, GAMEOVER } enumGameState;

	//Fonts
	sf::Font font;

	//Sprites
	sf::Sprite sprite;

	//For background
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	//Menu Animation
	MenuAnimator* menuAnimator;
	GamePlay* gamePlay;

	//For menu
	sf::Texture textureMenuFruits;
	sf::RectangleShape menuFruits;
	sf::Sprite spriteMenuFruits;
	
	//Private Methods
	void initWindow();
	void initTextures();
	void initFonts();
	void initMenuAnimation();
public:
	//Constructor and Destructor
	Game();
	~Game();

	bool isRunning();
	void update();
	void render();
};

#endif