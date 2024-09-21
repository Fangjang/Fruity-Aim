#include "GamePlay.hpp"

//Private Methods
//Initializes the textures
void GamePlay::initTextures()
{
	//Initalize Fruit texture tile
	if (!textureFruitTile.loadFromFile("sprites/fruits.png"))
	{
		MessageBoxA(NULL, "ERROR::GAMEPLAY::INITTEXTURES::Failed to load fruit tile texture -fruitTile.png", "ERROR", MB_ICONERROR);
		std::cout << "ERROR::GAMEPLAY::INITTEXTURES::Failed to load fruit tile texture" << std::endl;
	}

	if (!textureWallSplash.loadFromFile("sprites/splash.png"))
	{
		MessageBoxA(NULL, "ERROR::GAMEPLAY::INITTEXTURES::Failed to load wall splash texture -wallSplash.png", "ERROR", MB_ICONERROR);
		std::cout << "ERROR::GAMEPLAY::INITTEXTURES::Failed to load wall splash texture" << std::endl;
	}

	//Set the fruit sprite, centering their origin and setting scale to 5.f
	//Apple
	spriteApple.setTexture(textureFruitTile);
	spriteApple.setTextureRect({ 1, 0, 13, 14 });
	spriteApple.setOrigin(spriteApple.getGlobalBounds().width / 2, spriteApple.getGlobalBounds().height / 2);
	spriteApple.setScale(sf::Vector2f(5.f, 5.f));

	//Watermelon
	spriteWatermelon.setTexture(textureFruitTile);
	spriteWatermelon.setTextureRect({ 2, 17, 13, 14 });
	spriteWatermelon.setOrigin(spriteWatermelon.getGlobalBounds().width / 2, spriteWatermelon.getGlobalBounds().height / 2);
	spriteWatermelon.setScale(sf::Vector2f(5.f, 5.f));

	//Strawberry
	spriteStrawberry.setTexture(textureFruitTile);
	spriteStrawberry.setTextureRect({ 2, 33, 12, 13 });
	spriteStrawberry.setOrigin(spriteStrawberry.getGlobalBounds().width / 2, spriteStrawberry.getGlobalBounds().height / 2);
	spriteStrawberry.setScale(sf::Vector2f(5.f, 5.f));

	//Orange
	spriteOrange.setTexture(textureFruitTile);
	spriteOrange.setTextureRect({ 66, 2, 12,  12 });
	spriteOrange.setOrigin(spriteOrange.getGlobalBounds().width / 2, spriteOrange.getGlobalBounds().height / 2);
	spriteOrange.setScale(sf::Vector2f(5.f, 5.f));

	//Grape
	spriteGrape.setTexture(textureFruitTile);
	spriteGrape.setTextureRect({ 50, 17, 13, 13 });
	spriteGrape.setOrigin(spriteGrape.getGlobalBounds().width / 2, spriteGrape.getGlobalBounds().height / 2);
	spriteGrape.setScale(sf::Vector2f(5.f, 5.f));	


	//Set the wall splash sprite dummy and centering their origin
	spriteWallSplash.setTexture(textureWallSplash);
	spriteWallSplash.setScale(sf::Vector2f(0.2f, 0.2f));
	spriteWallSplash.setOrigin(sf::Vector2f(80.f, 80.f));
}

//Initializes the variables
void GamePlay::initVariables()
{
	//Set mouse pressed false
	isMousePressed = false;

	//Adding fruits to the vecFruits
	vecSpriteDummyFruits.push_back(spriteApple);
	vecSpriteDummyFruits.push_back(spriteWatermelon);
	vecSpriteDummyFruits.push_back(spriteStrawberry);
	vecSpriteDummyFruits.push_back(spriteOrange);
	vecSpriteDummyFruits.push_back(spriteGrape);

	vecFruits.push_back(Fruit(spriteApple));
}

//Initializes the fonts
void GamePlay::initFonts()
{

}

//Initializes the game play
void GamePlay::initGamePlay()
{
	initTextures();
	initFonts();
	initVariables();
}

//Public Methods
//Constructor
GamePlay::GamePlay(sf::RenderWindow* window)
{
	this->window = window;
	initGamePlay();
}

//Destructor
GamePlay::~GamePlay()
{

}

//Updates the game play
void GamePlay::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!isMousePressed)
		{
			isMousePressed = true;

			auto mouse_pos = sf::Mouse::getPosition(*window); // Mouse position relative to the window
			auto translated_pos = window->mapPixelToCoords(mouse_pos);
			std::vector<Fruit>::iterator fruit = vecFruits.begin();
			//if clicked on the fruit delete
			for (;fruit != vecFruits.end();)
			{
				if (fruit->getGlobalBounds().contains(translated_pos))
				{
					vecWallSplash.push_back(WallSplash(
						spriteWallSplash, sf::Vector2f(translated_pos.x - 50, translated_pos.y - 60)));
					fruit = vecFruits.erase(fruit);
				}
				else
				{
					++fruit;
				}
			}
		}
	}
	else
	{
		isMousePressed = false;
	}

	//Update fruit
	for (auto& fruit : vecFruits)
	{
		fruit.update();
	}

	//Update the wall splash
	std::vector<WallSplash>::iterator wallSplash = vecWallSplash.begin();
	for (;wallSplash != vecWallSplash.end();)
	{
		wallSplash->update();
		if (wallSplash->isDestroyed())
		{
			wallSplash = vecWallSplash.erase(wallSplash);
		}
		else
		{
			++wallSplash;
		}
	}
}

//Renders the game play
void GamePlay::render(sf::RenderWindow* window)
{
	//Render the wall splash
	for (auto& wallSplash : vecWallSplash)
	{
		wallSplash.render(window);
	}

	for (auto& fruit : vecFruits)
	{
		fruit.render(*window);
	}
}