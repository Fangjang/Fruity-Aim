#ifndef WALLSPLASH_HPP
#define WALLSPLASH_HPP

#include "directives.hpp"

class WallSplash
{
private:
	//Render Window
	sf::RenderWindow* window;

	//Sprite
	sf::Sprite spriteWallSplash;

	//Animation State
	enum class AnimationState
	{
		STATIC,
		FADE_OUT,
		DESTROY
	} enumAnimationState;

	//Animation Timing
	sf::Clock clock;
	float fAnimationTime;

	//Static animation duration
	float fStaticDuration;
	float fFadeOutSpeed;

	//Private methods
	void initVariables();
	void initTextures();
	void initWallSplash();
public:
	//Constructor and Destructor
	WallSplash(sf::Sprite spriteWallSplash, sf::Vector2f position);
	~WallSplash();

	//Public Methods
	bool isDestroyed();

	//Update and render
	void update();
	void render(sf::RenderWindow* window);
};

#endif // !WALLSPLASH_HPP
