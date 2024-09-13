#include "Game.hpp"

///
/// PRIVATE METHODS
/// 

//Initializes the window
void Game::initWindow()
{
	//Create a window
	try
	{
		window.create(sf::VideoMode(800, 600), "Fruity Aim", sf::Style::Titlebar | sf::Style::Close);
	}
	catch (const std::exception& e)
	{
		MessageBoxA(NULL, "ERROR::GAME::INITWINDOW::Failed to create window", "ERROR", MB_ICONERROR);
		std::cout << "ERROR::GAME::INITWINDOW::Failed to create window" << e.what() << std::endl;
		
	}
	//Set frame per second limit
	window.setFramerateLimit(60);
}

//Initiliaze Textures
void Game::initTextures()
{
	//Initalize Background texture
	if (!textureBackground.loadFromFile("sprites/bgTile.jpg"))
	{
		MessageBoxA(NULL, "ERROR::GAME::INITTEXTURES::Failed to load background texture -background.jpg", "ERROR", MB_ICONERROR);
		std::cout << "ERROR::GAME::INITTEXTURES::Failed to load background texture" << std::endl;
	}
	textureBackground.setRepeated(true);
	//Initliaze background texture all over  the screen
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setTextureRect({ 0, 0, 800, 600 });

	//Initialize Menu Fruits texture
	if (!textureMenuFruits.loadFromFile("sprites/menuFruits.png"))
	{
		MessageBoxA(NULL, "ERROR::GAME::INITTEXTURES::Failed to load menu fruits texture -menuFruits.png", "ERROR", MB_ICONERROR);
		std::cout << "ERROR::GAME::INITTEXTURES::Failed to load menu fruits texture" << std::endl;
	}
	//Initialize menu fruits sprite
	spriteMenuFruits.setTexture(textureMenuFruits);
	spriteMenuFruits.setScale(sf::Vector2f(0.8f, 0.8f));
	spriteMenuFruits.setPosition(sf::Vector2f(200, 40));
}

//Initialize Fonts
void Game::initFonts()
{
	if (!font.loadFromFile("Fonts/font.ttf"))
	{
		MessageBoxA(NULL, "ERROR::GAME::INITFONTS::Failed to load font -Font.ttf", "ERROR", MB_ICONERROR);
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font" << std::endl;
	}
}

//Initialize menu animation
void Game::initMenuAnimation()
{
	menuAnimator = new MenuAnimator(&spriteMenuFruits, 18.f, 2.8f, &font);
}

/// 
/// PUBLIC METHODS
/// 
//Constructor and Destructor
Game::Game()
{
	menuAnimator = nullptr;
	initWindow();
	initTextures();
	initFonts();
	initMenuAnimation();
}
//Destructor
Game::~Game()
{

}

//Returns the status of the window
bool Game::isRunning()
{
	return window.isOpen();
}

//Updates the game
void Game::update()
{
	//Event polling
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		delete menuAnimator;
		menuAnimator = nullptr;
		window.close();
		exit(0);
	}

	//Update menu animation
	menuAnimator->update();
}

//Renders the game
void Game::render()
{
	//Drawing background
	window.draw(spriteBackground);
	
	//Drawing menu animation
	if (menuAnimator != nullptr)
	{
		menuAnimator->render(window);
	}

	//Displaying window
	window.display();
}
