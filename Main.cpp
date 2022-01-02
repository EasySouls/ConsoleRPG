#include <iostream>
#include "Game.h"

int main()
{
	srand(time(NULL));
	Game game;
	game.initGame();

	Inventory inv;
	inv.addItem(Item());
	inv.debugPrint();

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}


