#include "Game.h"

Game::Game()
{
	choice = 0;
	canRest = false;
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
	cin.ignore();
	cin.get();
	/*system("CLS");*/

	if (characters[activeCharacter].isAlive())
	{
		cout << "= MAIN MENU =" << endl << endl;;
		cout << "Active character: " << this->characters[activeCharacter].getName() << " " << this->activeCharacter+1 << " / " << this->characters.size() << "\n" << endl;
		if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
		{
			cout << "Level up available!\n" << endl;
		}
		cout << "[0]: Quit" << endl;
		cout << "[1]: Travel" << endl;
		cout << "[2]: Shop" << endl;
		cout << "[3]: Level up" << endl;
		cout << "[4]: Rest" << endl;
		cout << "[5]: Character sheet" << endl;
		cout << "[6]: Create new character" << endl;
		cout << "[7]: Save characters" << endl;
		cout << "[8]: Load characters" << endl;
		cout << "[9]: Select character" << endl;
		cout << endl;

		cout << "Choice: ";
		cin >> this->choice;
		cout << endl;

		while (cin.fail())
		{
			cout << "Wrong input!" << endl;
			cin.clear();
			cin.ignore(100, '\n');

			std::cout << endl << "Choice :";
			cin >> this->choice;
		}

		/*cin.ignore(100, '\n');
		cout << endl;*/

		switch (this->choice)
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
			levelUpCharacter();
			break;

		case 4: //REST
			Rest();
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

		case 9: //SELECT CHARACTER
			selectCharacter();
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "YOU ARE DEAD!\n" << endl;
		cout << "Press [1] to load a previous character or press [0] to quit" << endl;
		cin >> this->choice;

		while (cin.fail() || this->choice < 0 || this->choice > 1)
		{
			cout << "Even after death, you do not care enough to avoid your mistakes." << endl;
			cout << "Your options were [1] and [0]" << endl;
			cin >> this->choice;
			cout << endl;
		}

		if (this->choice == 1)
		{
			loadCharacters();
			selectCharacter();
		}
		else
		{
			cout << "You have failed to live up to the expectations, adventurer.\n" << endl;
			playing = false;
		}
	}

}

void Game::createNewCharacter()
{
	string name;
	cout << "Enter the name of your character: ";
	getline(cin, name);
	cout << "\n" << endl;

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			cout << "Error! Character with the same name already exists!" << endl;
			cout << "Enter the name of your character: ";
			getline(cin, name);
		}
	}

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initalize(name);
}

void Game::levelUpCharacter()
{
	this->characters[activeCharacter].levelUp();
	int unspentStatP = this->characters[activeCharacter].getStatsPoints();
	int unspentSkillP = this->characters[activeCharacter].getSkillPoints();

	if (unspentStatP > 0)
	{
		cout << "\nYou have " + to_string(unspentStatP) + " unspent stat points.\n" << endl;
		cout << "Stats to upgrade: " << endl;
		cout << "[1] Strenght -- " + to_string(this->characters[activeCharacter].getStrenght()) << endl;
		cout << "[2] Vitality -- " + to_string(this->characters[activeCharacter].getVitality()) << endl;
		cout << "[3] Dexterity -- " + to_string(this->characters[activeCharacter].getDexterity()) << endl;
		cout << "[4] Intelligence -- " + to_string(this->characters[activeCharacter].getIntelligence()) << endl;

		cout << "Your choice: ";
		cin >> this->choice;
		cout << endl;

		while (cin.fail() || this->choice > 4)
		{
			cout << "Wrong input!" << endl;
			cin.clear();
			cout << "Your choice: ";
			cin >> this->choice;
			cout << endl;
		}

		switch (this->choice)
		{
		case 1:
			this->characters[activeCharacter].upgradeStrenght();
			this->characters[activeCharacter].addStatPoints(-1);
			cout << "Strenght upgraded!\n" << endl;
			break;
		case 2:
			this->characters[activeCharacter].upgradeVitality();
			this->characters[activeCharacter].addStatPoints(-1);
			cout << "Vitality upgraded!\n" << endl;
			break;
		case 3:
			this->characters[activeCharacter].upgradeDexterity();
			this->characters[activeCharacter].addStatPoints(-1);
			cout << "Dexterity upgraded!\n" << endl;
			break;
		case 4:
			this->characters[activeCharacter].upgradeIntelligence();
			this->characters[activeCharacter].addStatPoints(-1);
			cout << "Intelligence upgraded!\n" << endl;
			break;
		default:
			cout << "Wrong input. Press level up again to upgrade your stats!\n" << endl;
			break;
		}

		this->characters[activeCharacter].updateStats();
	}
	else cout << "You have no unspent stat points!\n" << endl;
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

void Game::selectCharacter()
{
	cout << "Select character: \n" << endl;

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		cout << "[" << i << "] " << this->characters[i].getName() << " (lvl " << this->characters[i].getLevel() << ")" << endl;
	}

	cout << "Choice: ";
	cin >> this->choice;

	while (cin.fail() || this->choice >= this->characters.size() || this->choice < 0)
	{
		cout << "Wrong input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Select character: ";
		cin >> this->choice;
	}

	this->activeCharacter = this->choice;
	cout << this->characters[activeCharacter].getName() << " is selected.\n" << endl;
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event ev;
	ev.generateEvent(this->characters[activeCharacter], this->enemies);
	canRest = true;
}

void Game::Rest()
{
	if (canRest)
	{
		if (this->characters[activeCharacter].getHPMax() == this->characters[activeCharacter].getHP())
		{
			cout << "You are already at max hp.\n" << endl;
		}
		else 
		{
			cout << "You take a rest under a nearby tree and regain some of you hp" << endl;
			int level = characters[activeCharacter].getLevel();
			characters[activeCharacter].heal(level * 10);
			canRest = false;
			cout << "You healed for" << level * 10 << " points" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "You have already taken a rest this day" << endl;
		cout << "Only after traveling will you be able to rest again" << endl;
		cout << endl;
	}
}
