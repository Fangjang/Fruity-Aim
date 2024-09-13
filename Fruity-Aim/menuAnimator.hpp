#ifndef MENU_ANIMATOR_HPP
#define MENU_ANIMATOR_HPP

#include "directives.hpp"

class MenuAnimator
{
private:
	//Menu Animation Var
	sf::Sprite* spriteMenuFruits;

	//Clock
	float deltaTime;
	sf::Clock clock;

	//State of floating animation 
	enum class MenuState
	{
		UP,
		DOWN
	} enumMenuState;

	//Animation Variables
	float floatDist;
	float currentDist;
	float speed;

	//Font
	//UI font
	sf::Font* font;
	//Title font
	sf::Font fontTitle;
	
	//Menu Text;
	sf::Text textTitle;
	sf::Text textStartPrompt;

	//Private Methods
	void initFont();
	void initAnimation();
public:
	//Constructor and Destructor
	MenuAnimator(sf::Sprite* spriteMenuFruits, float floatDist, float speed, sf::Font* font);
	~MenuAnimator();

	//Public Methods
	void update();
	void render(sf::RenderWindow& window);
};

#endif // !MENU_ANIMATOR_HPP
