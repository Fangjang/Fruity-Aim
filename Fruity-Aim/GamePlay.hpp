#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "directives.hpp"
#include "Fruit.hpp"
#include "WallSplash.hpp"

class GamePlay
{
private:
	//DEBUG
	bool bisXpressed;


	//GamePlay Variables
	sf::RenderWindow* window;

	//mouse pressed state
	bool isMousePressed;

	//Textures
	sf::Texture textureFruitTile;
	sf::Texture textureWallSplash;

	//Fruits
	sf::Sprite spriteApple;
	sf::Sprite spriteWatermelon;
	sf::Sprite spriteStrawberry;
	sf::Sprite spriteOrange;
	sf::Sprite spriteGrape;
	std::vector<sf::Sprite> vecSpriteDummyFruits;

	//Cutable Fruits
	std::vector<Fruit> vecFruits;

	//Wall Splash Sprite
	sf::Sprite spriteWallSplash;
	std::vector<WallSplash> vecWallSplash;

	//GamePlay Methods
	void initTextures();
	void initVariables();
	void initFonts();
	void initGamePlay();

public:
	//Constructor and Destructor
	GamePlay(sf::RenderWindow* window);
	~GamePlay();

	//Public Methods
	void update();
	void render(sf::RenderWindow* window);
};

#endif // !GAMEPLAY_HPP

