#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
}

Game::~Game()
{

}

// Functions
void Game::InitGame()
{
	string name;
	cout << "Enter the name of your character: ";
	getline(cin, name);

	player.Initalize(name);

}

void Game::MainMenu()
{
	cout << "MAIN MENU" << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;
	cout << endl;

	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		player.PrintStats();
		break;
	default:
		break;
	}
}