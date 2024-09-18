#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "directives.hpp"

class Fruit
{
private:
	//Fruit Variables
	sf::RenderWindow* window;

	//Rotation Direction for animation
	enum class RotationDirection
	{
		LEFT,
		RIGHT
	} enumRotationDirection;

	//Main Furut Sprite
	sf::Sprite spriteFruit;

	//Fruit Methods
	void initTextures();
	void initVariables();
	void initFruit();

public:
	//Constructor and Destructor
	Fruit(sf::Sprite fruit);
	~Fruit();

	//Public Methods
	//Return position of sprite
	sf::Vector2f getPosition();
	//Return Global Bounds of sprite
	sf::FloatRect getGlobalBounds();

	void update();
	void render(sf::RenderWindow& window);
};

#endif // !FRUIT_HPP
