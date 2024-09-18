#ifndef MENU_ANIMATOR_HPP
#define MENU_ANIMATOR_HPP

#include "directives.hpp"

class MenuAnimator
{
private:
	//menuAnimation complete
	bool isMenuAnimationComplete;
	bool wrapUp;

	//Menu Animation Var
	sf::Sprite* spriteMenuFruits;

	//Clock
	float deltaTime;
	sf::Clock clock;

	//State of floating animation 
	enum class MenuState
	{
		UP,
		DOWN,
		STATIC,
		START_GAME
	} enumMenuState;
	bool gameStart;

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

	//Menu Black screen animation
	sf::RectangleShape rectBlackScreen;
	float positionY;

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
	void setMenuStatic();
	bool isMenuStatic();
	bool isWrapUp();;
};

#endif // !MENU_ANIMATOR_HPP
