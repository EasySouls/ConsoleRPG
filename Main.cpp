#include <iostream>
#include "Game.h"

int main()
{
	srand(time(NULL));
	Game game;
	game.InitGame();

	while (game.getPlaying())
	{
		game.MainMenu();
	}

	return 0;
}


