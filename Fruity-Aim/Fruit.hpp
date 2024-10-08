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

	//enum Falling state
	enum class FallingState
	{
		RISING,
		FALLING,
		DESTROY
	} enumFallingState;

	//First fruit
	bool bFirstFruit;

	//Maximum height and Spwaning Position
	float fMaxHeight;
	float fSpwanXpos;

	//Rotation Speed
	float fRotationSpeed;
	//X axix move Threshold
	float fMoveThresholdX;

	//GRAVITY
	// fInitialSpeedY
	//low : 14f
	//High: 18f
	float fInitialSpeedY;
	float fgravity = 15.0f;
	//Clock
	sf::Clock clock;

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
	

	bool isDestroy();

	void update();
	void render(sf::RenderWindow& window);
};

#endif // !FRUIT_HPP
