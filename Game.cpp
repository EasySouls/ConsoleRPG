#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";
}

Game::~Game()
{

}

// Functions
void Game::initGame()
{
	createNewCharacter();
}

void Game::mainMenu()
{
	cout << "MAIN MENU" << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;
	cout << "6: Create new character" << endl;
	cout << "7: Save characters" << endl;
	cout << "8: Load characters" << endl;
	cout << endl;

	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 0: //QUIT
		playing = false;
		break;

	case 1: //TRAVEL
		Travel();
		break;

	case 2: //SHOP
		break;

	case 3: //LEVEL UP
		break;

	case 4: //REST
		break;

	case 5: //CHARACTER SHEET
		characters[activeCharacter].printStats();
		break;

	case 6: //CREATE NEW CHARACTER
		cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;

	case 7: //SAVE CHARACTER
		saveCharacters();
		break;

	case 8: //LOAD CHARACTERS
		loadCharacters();
		break;

	default:
		break;
	}
}

void Game::createNewCharacter()
{
	string name;
	cout << "Enter the name of your character: ";
	getline(cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initalize(name);
}

void Game::saveCharacters()
{
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}
	outFile.close();
}

void Game::loadCharacters()
{

}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event ev;
	ev.generateEvent(this->characters[activeCharacter]);
}
