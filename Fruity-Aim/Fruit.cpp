#include "Fruit.hpp"

//Private Methods
//Initializes the Fruit Textures
void Fruit::initTextures()
{

}

//Initializes the Fruit Variables
void Fruit::initVariables()
{
	//Set the Rotation Direction
	enumRotationDirection = RotationDirection::LEFT;

	//Set the Fruit Sprite position
	spriteFruit.setPosition(100.0f, 100.0f);
}

//Initializes the Fruit
void Fruit::initFruit()
{
	//Set the Fruit Sprite

}

//Public Methods
//Fruit Constructor
Fruit::Fruit(sf::Sprite fruit)
{
	//Set the Fruit Sprite
	this->spriteFruit = fruit;

	//Initialize Fruit
	initVariables();
	initTextures();
	initFruit();
}

//Fruit Destructor
Fruit::~Fruit()
{

}

//Return position of sprite
sf::Vector2f Fruit::getPosition()
{
	return spriteFruit.getPosition();
}

//Return Global Bounds of sprite
sf::FloatRect Fruit::getGlobalBounds()
{
	return spriteFruit.getGlobalBounds();
}

//Updates the Fruit
void Fruit::update()
{
	spriteFruit.rotate(2.0f);
}

//Renders the Fruit
void Fruit::render(sf::RenderWindow& window)
{
	//Render the Fruit
	window.draw(spriteFruit);
}