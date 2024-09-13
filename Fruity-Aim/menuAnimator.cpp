#include "menuAnimator.hpp"

//Private Methods

void MenuAnimator::initFont()
{
	//Menu Texts
	//Title Text
	if (!fontTitle.loadFromFile("Fonts/title.ttf"))
	{
		std::cout << "ERROR::MENU_ANIMATOR::Could not load font" << std::endl;
	}
	textTitle.setFont(fontTitle);
	textTitle.setString("FRUITY AIM");
	textTitle.setPosition(sf::Vector2f(130, 260));
	textTitle.setCharacterSize(70);
	textTitle.setOutlineColor(sf::Color::Black);
	textTitle.setOutlineThickness(2.f);

	//Start Prompt Text
	textStartPrompt.setFont(*font);
	textStartPrompt.setString("Click Left Mouse Button To Start");
	textStartPrompt.setPosition(sf::Vector2f(190, 360));
	textStartPrompt.setCharacterSize(40);
	textStartPrompt.setOutlineColor(sf::Color::Black);
	textStartPrompt.setOutlineThickness(2.f);

	
}

//Init Animation
void MenuAnimator::initAnimation()
{
	//Menu Fruits animation state
	enumMenuState = MenuState::DOWN;

	//Clock and Animation Variables
	deltaTime = 0.f;
	currentDist = 0.f;
}



//Public Methods
//Constructor
MenuAnimator::MenuAnimator(sf::Sprite* spriteMenuFruits, float floatDist, float speed, sf::Font* Font)
{

	this->spriteMenuFruits = spriteMenuFruits;
	this->floatDist = floatDist;
	this->speed = speed;	
	this->floatDist = floatDist;
	this->font = Font;
	initAnimation();
	initFont();
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
		float tempAlpha = textStartPrompt.getFillColor().a;
		switch (enumMenuState)
		{
		case MenuAnimator::MenuState::UP:
			spriteMenuFruits->move(0.f, -speed);
			textTitle.move(0.f, -1.8);
			currentDist += speed;
			textStartPrompt.setFillColor(sf::Color(255, 255, 255, tempAlpha + 15));
			if (currentDist >= floatDist)
			{
				currentDist = 0.f;
				enumMenuState = MenuState::DOWN;
			}
			clock.restart();
			break;
		case MenuAnimator::MenuState::DOWN:
			spriteMenuFruits->move(0.f, speed);
			textTitle.move(0.f, 1.8);
			textStartPrompt.setFillColor(sf::Color(255, 255, 255, tempAlpha - 15));
			currentDist += speed;
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
	window.draw(*spriteMenuFruits);
	window.draw(textStartPrompt);
	window.draw(textTitle);
}
