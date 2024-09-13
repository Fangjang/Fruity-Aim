#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include "directives.hpp"

//Animator Class
class Animator
{
	//Private Variables
private:
	//Render Window pointer
	sf::RenderWindow* window;

	// Sprite to be animated
	sf::Sprite sprite;

	//Sprite location
	sf::Vector2f position;

	// Frame size
	int frameWidth;
	int frameHeight;

	// Animation timing
	float frameDuration; // Time between frames
	float elapsedTime;   // Time since last frame update

	// Frame control
	int currentFrame;    // Current frame index
	int totalFrames;     // Total number of frames in the animation

	//Initialize Sprite
	void initAnimation();

	//Public Variables
public:
	//Constructor and Destructor
	Animator(sf::RenderWindow* window, sf::Sprite sprite, int frameWidth, int frameHeight, int totalFrames, float frameDuration);
	~Animator();

	//Public Methods
	void update();
	void render();
};

#endif // !ANIMATOR_HPP
