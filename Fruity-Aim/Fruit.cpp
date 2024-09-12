#include"Game.hpp"

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
