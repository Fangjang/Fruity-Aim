#ifndef MENU_ANIMATOR_HPP
#define MENU_ANIMATOR_HPP

#include "directives.hpp"

class MenuAnimator
{
private:
	//Menu Animation Var
	sf::Sprite spriteMenuFruits;

	//Clock
	float deltaTime;
	sf::Clock clock;

	//State of floating animation 
	enum class MenuState
	{
		UP,
		DOWN
	} enumMenuState;

	float floatDist;
	float currentDist;
	float speed;
	
	//Private Methods
	void initAnimation();
public:
	//Constructor and Destructor
	MenuAnimator(sf::Sprite& spriteMenuFruits, float floatDist, float speed);
	~MenuAnimator();

	//Public Methods
	void update();
	void render(sf::RenderWindow& window);
};

#endif // !MENU_ANIMATOR_HPP
