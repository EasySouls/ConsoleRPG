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
	cout << "ENTER to continue..." << endl;
	cin.get();
	system("CLS");

	cout << "= MAIN MENU =" << endl << endl;;
	if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
	{
		cout << "Level up available!\n" << endl;
	}
	cout << "= 0: Quit" << endl;
	cout << "= 1: Travel" << endl;
	cout << "= 2: Shop" << endl;
	cout << "= 3: Level up" << endl;
	cout << "= 4: Rest" << endl;
	cout << "= 5: Character sheet" << endl;
	cout << "= 6: Create new character" << endl;
	cout << "= 7: Save characters" << endl;
	cout << "= 8: Load characters" << endl;
	cout << endl;

	cout << "Choice: ";
	cin >> choice;
	cout << endl;

	while (cin.fail())
	{
		cout << "Wrong input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');

		std::cout << endl << "Choice :";
		cin >> choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

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
		this->characters[activeCharacter].levelUp();
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
	cout << "\n" << endl;

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

	cout << this->characters[activeCharacter].getName() + " is saved!\n" << endl;
}

void Game::loadCharacters()
{
	ifstream inFile(fileName);

	//this->characters.clear();

	string name;
	int level, distanceTraveled, gold, exp, strenght, vitality, dexterity, intelligence, hp, stamina, statPoints, skillPoints;
	string line = "";
	stringstream str;


	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceTraveled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strenght;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;
			str >> skillPoints;

			Character temp(name, distanceTraveled, gold, level, exp, strenght, vitality, dexterity, intelligence, hp, stamina, statPoints, skillPoints);

			this->characters.push_back(Character(temp));
			cout << "Character " + name + " loaded!\n" << endl;
			str.clear();
		}
	}
	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw "ERROR! NO CHARACTER LOADED OR EMPTY FILE!";
	}
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event ev;
	ev.generateEvent(this->characters[activeCharacter]);
}
