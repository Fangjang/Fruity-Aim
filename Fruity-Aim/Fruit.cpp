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
	//Set falling state
	enumFallingState = FallingState::RISING;

	//Set Rotation Speed
	fRotationSpeed = 5.0f;

	//Set Gravity
	fMaxHeight = rand() % (320 - 180) + 180;
	//Set Spwaning Position on X axis
	fSpwanXpos = rand() % (780 - 250) + 250;

	//X axis move Threshold
	fMoveThresholdX = 1.5f;
	//Y axis move Threshold
	fMoveThresholdY = 1.2f;
	//Initial Speed
	fInitialSpeed = 20.0f;

	//Set the Fruit Sprite position
	spriteFruit.setPosition(fSpwanXpos, 620.0f);
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
	//Rotate the Fruit
	switch (enumRotationDirection)
	{
	case Fruit::RotationDirection::LEFT:
		spriteFruit.rotate(-fRotationSpeed);
		spriteFruit.move(-fMoveThresholdX, 0.0f);
		break;
	case Fruit::RotationDirection::RIGHT:
		spriteFruit.rotate(fRotationSpeed);
		spriteFruit.move(fMoveThresholdX, 0.0f);
		break;
	default:
		break;
	}

	switch (enumFallingState)
	{
	case Fruit::FallingState::RISING:
		{
			float tempYthrehold = fMoveThresholdY * (1.1 - fMoveThresholdY);
			if (spriteFruit.getPosition().y > fMaxHeight && !(spriteFruit.getPosition().y - tempYthrehold < fMaxHeight))
			{
				float tempY = fInitialSpeed * tempYthrehold;
				spriteFruit.move(0.0f, -tempY);
			}
			else
			{
				enumFallingState = FallingState::FALLING;
			}
			break;
		}
	case Fruit::FallingState::FALLING:
		{
			if (spriteFruit.getPosition().y < 650)
			{
				spriteFruit.move(0.0f, 20);
			}
			else
			{
				enumFallingState = FallingState::DESTROY;
			}
			break;
		}
	case Fruit::FallingState::DESTROY:
		{
			break;
		}
	default:
		break;
	}
}

//Renders the Fruit
void Fruit::render(sf::RenderWindow& window)
{
	//Render the Fruit
	window.draw(spriteFruit);
}