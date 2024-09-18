///
///Built using SFML ver 2.6.0

#include"Game.hpp"

//Main function
int main()
{
	//Create Game object
	Game game;
	while (game.isRunning())
	{
		//Game Loop
		game.update();
		game.render();
	}
	return 0;
}
