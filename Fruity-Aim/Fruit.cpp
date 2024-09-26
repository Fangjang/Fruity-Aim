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
	bool tempDirectionLeft = rand() % 2;
	if (tempDirectionLeft)
	{
		enumRotationDirection = RotationDirection::LEFT;
	}
	else
	{
		enumRotationDirection = RotationDirection::RIGHT;
	}

	//Set falling state
	enumFallingState = FallingState::RISING;

	//Set Rotation Speed
	fRotationSpeed = 5.0f;

	//Set Gravity
	fMaxHeight = rand() % (300 - 100) + 100;
	//Set Spwaning Position on X axis
	fSpwanXpos = rand() % (690 - 115) + 115;

	//Random Initial speed on y axis
	fInitialSpeedY = rand() % (18 - 14) + 14;

	//X axis move Threshold
	fMoveThresholdX = 1.5f;

	//GRAVITY
	//CLOCK
	clock.restart();

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
	std::cout << "Fruit Sprite Destroyed" << std::endl;
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

//Return true if enumFallingState is DESTROY
bool Fruit::isDestroy()
{
	if (enumFallingState == FallingState::DESTROY)
	{
		return true;
	}
	return false;
}

//Updates the Fruit
void Fruit::update()
{
	std::cout << fMaxHeight << std::endl;
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
			//TEMP variables
			std::cout << "Y: " << spriteFruit.getPosition().y << std::endl;	
			float fTempVelocity = fgravity * clock.getElapsedTime().asSeconds();
			std::cout << "Velocity: " << fTempVelocity << std::endl;

			if (fInitialSpeedY - fTempVelocity < 0)
			{
				float fTempTempVelocity = fMaxHeight - ((spriteFruit.getPosition().y) - (fInitialSpeedY - fTempVelocity));
				std::cout << "Temp Velocity: " << fTempVelocity << std::endl;
				spriteFruit.move(0.0f, -0.0f);
				enumFallingState = FallingState::FALLING;
				clock.restart();
			}
			else
			{
				spriteFruit.move(
					0.0f, -(fInitialSpeedY - fTempVelocity) + 2.0f);
			}
			break;
		}
	case Fruit::FallingState::FALLING:
		{
			//TEMP variables
			float fTempVelocity = fgravity * clock.getElapsedTime().asSeconds();

			//Moving sprite with new velocity
			spriteFruit.move(0.0f, fTempVelocity + 2.0f);
			if (spriteFruit.getPosition().y > 650)
			{
				enumFallingState = FallingState::DESTROY;
			}
			break;
		}
	case Fruit::FallingState::DESTROY:
		{
			std::cout << "ENUM: DESTROY" << std::endl;
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