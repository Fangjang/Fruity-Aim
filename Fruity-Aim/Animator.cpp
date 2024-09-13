#include "Animator.hpp"

/// ////////////////
/// Private Methods
/// ///////////////

//Initialize Sprite
void Animator::initAnimation()
{
	//Initialize position
	position = sf::Vector2f(0.0f, 0.0f);
}

/////////////////////////////////
///					////////////
/// Public Methods  ////////////
/// ///////////////////////////
//Constructor
Animator::Animator(sf::RenderWindow* window, sf::Sprite sprite, int frameWidth, int frameHeight, int totalFrames, float frameDuration)
	:window(window), sprite(sprite), frameWidth(frameWidth), frameHeight(frameHeight),
	totalFrames(totalFrames), frameDuration(frameDuration), currentFrame(0), elapsedTime(0.0f)
{
	initAnimation();
}
//Destructor
Animator::~Animator()
{

}

//Updates the animation
void Animator::update()
{

}

//Renders the animation
void Animator::render()
{

}
