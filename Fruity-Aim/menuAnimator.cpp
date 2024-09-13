#include "menuAnimator.hpp"

//Private Methods
//Init Animation
void MenuAnimator::initAnimation()
{
	enumMenuState = MenuState::DOWN;
	deltaTime = 0.f;
	currentDist = 0.f;
}



//Public Methods
//Constructor
MenuAnimator::MenuAnimator(sf::Sprite& spriteMenuFruits, float floatDist, float speed)
{
	initAnimation();
	this->spriteMenuFruits = spriteMenuFruits;
	this->floatDist = floatDist;
}

//Destructor
MenuAnimator::~MenuAnimator()
{

}

//Update
void MenuAnimator::update()
{
	//Animate the menu
	if (deltaTime >= 100.f)
	{
		switch (enumMenuState)
		{
		case MenuAnimator::MenuState::UP:
			spriteMenuFruits.move(0.f, -speed);
			if (currentDist >= floatDist)
			{
				currentDist = 0.f;
				enumMenuState = MenuState::DOWN;
			}
			clock.restart();
			break;
		case MenuAnimator::MenuState::DOWN:
			spriteMenuFruits.move(0.f, speed);
			if (currentDist >= floatDist)
			{
				currentDist = 0.f;
				enumMenuState = MenuState::UP;
			}
			clock.restart();
			break;
		default:
			break;
		}
	}
	deltaTime = clock.getElapsedTime().asMilliseconds();
}

//Render
void MenuAnimator::render(sf::RenderWindow& window)
{
	window.draw(spriteMenuFruits);
}
