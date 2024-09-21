#include "WallSplash.hpp"

//Private Methods
//Initializes the WallSplash Variables
void WallSplash::initVariables()
{
	//Set the WallSplash Sprite position
	enumAnimationState = AnimationState::STATIC;

	//Animation Timing
	clock.restart();
	fAnimationTime = 300.0f;
	fStaticDuration = 600.0f;
	fFadeOutSpeed = 20.f;
}

//Initializes the WallSplash Textures
void WallSplash::initTextures()
{

}

//Initializes the WallSplash
void WallSplash::initWallSplash()
{

}

//Public Methods
//WallSplash Constructor
WallSplash::WallSplash(sf::Sprite spriteWallSplash, sf::Vector2f position)
{
	//Set the WallSplash Sprite
	this->spriteWallSplash = spriteWallSplash;
	this->spriteWallSplash.setPosition(position);

	//Initialize WallSplash
	initVariables();
	initTextures();
	initWallSplash();
}

//WallSplash Destructor
WallSplash::~WallSplash()
{

}

bool WallSplash::isDestroyed()
{
	if (enumAnimationState == AnimationState::DESTROY)
	{
		return true;
	}
	return false;
}

//Updates the WallSplash
void WallSplash::update()
{
	if (enumAnimationState == AnimationState::STATIC)
	{
		//Check if the Static Duration has passed
		if (clock.getElapsedTime().asMilliseconds() >= fStaticDuration)
		{
			//Set the Animation State to Fade Out
			enumAnimationState = AnimationState::FADE_OUT;
			clock.restart();
		}
	}
	else if (enumAnimationState == AnimationState::FADE_OUT)
	{
		if (spriteWallSplash.getColor().a > 0 && !(spriteWallSplash.getColor().a - fFadeOutSpeed < 0))
		{
			//Fade Out the WallSplash
			spriteWallSplash.setColor(sf::Color(255, 255, 255, spriteWallSplash.getColor().a - fFadeOutSpeed));
		}
		else
		{
			//Set the Animation State to Destroy
			enumAnimationState = AnimationState::DESTROY;
		}
	}
}

//Renders the WallSplash
void WallSplash::render(sf::RenderWindow* window)
{
	window->draw(spriteWallSplash);
}