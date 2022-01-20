#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character, dArray<Enemy>& enemies)
{
	int i = rand() % this->nrOfEvents;

	switch (i)
	{
	case 0:
		// Enemy encounter
		enemyEncounter(character, enemies);
		break;
	case 1:
		// Puzzle
		puzzleEncounter(character);
		break;
	case 2:
		break;
	default:
		break;
	}
}

// Different events
void Event::enemyEncounter(Character& character, dArray<Enemy>& enemies)
{
	bool playerTurn = false;
	int choice = 0;

	// Coin toos for turn
	int coinToss = rand() % 2 + 1;

	if (coinToss == 1)
		playerTurn = true;
	else 
		playerTurn = false;

	bool escaped = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;

	int nrOfEnemies = rand() % 5;
	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies.push(Enemy(character.getLevel()));
	}
	
	while (!escaped && !playerDefeated && !enemiesDefeated)
	{
		if (playerTurn && !playerDefeated) //on player turn
		{
			// Combat UI
			cout << " = BATTLE MENU = \n" << endl;
			cout << "[0] Escape" << endl;
			cout << "[1] Attack" << endl;
			cout << "[2] Defend" << endl;
			cout << "[3] Use Item" << endl;
			cout << endl;

			cout << "Choice: ";
			cin >> choice;
			cout << endl;

			while (cin.fail() || choice > 3 || choice < 0)
			{
				system("CLS");

				cout << "Wrong input!\n" << endl;
				cin.clear();
				cin.ignore(100, '\n');

				cout << " = BATTLE MENU = \n" << endl;
				cout << "[0] Escape" << endl;
				cout << "[1] Attack" << endl;
				cout << "[2] Defend" << endl;
				cout << "[3] Use Item" << endl;
				cout << endl;

				std::cout << endl << "Choice: ";
				cin >> choice;
			}

			// Moves
			switch (choice)
			{
			case 0:
				escaped = true;
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
			}

			// End turn
			playerTurn = false;
		}
		else if (!playerTurn && !escaped && !enemiesDefeated) // On enemies' turn
		{
			for (size_t i = 0; i < enemies.size(); i++)
			{
				// The enemy attacks the player
			}
			// End turn
			playerTurn = true;
		}

		// Conditions
		if (!character.isAlive())
		{
			playerDefeated = true;

		}
		else if (enemies.size() <= 0)
		{
			enemiesDefeated = true;

		}
	}
}

void Event::puzzleEncounter(Character& character)
{
	cin.ignore();
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	// You get exp depending on your current level
	int rewardExp = (chances * (character.getLevel()) * 50) / 2;
	Puzzle puzzle("Puzzles/p1.txt"); 

	while (!completed && chances > 0)
	{
		cout << puzzle.getAsString() << endl;
		cout << "Remaining chances: " << chances << endl;

		cout << "\nYour answer: ";
		cin >> userAns;
		
		while (cin.fail())
		{
			cout << "Wrong input!" << endl;
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Your answer: ";
			cin >> userAns;
		}

		cin.ignore(100, '\n');
		cout << endl;

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;

			character.gainExp(rewardExp);
			//GIVE USER EXP ETC AND CONTINUE
		}
		chances--;
	}
	if (completed)
	{
		cout << "You succeeded in solving the puzzle." << endl;
		cout << "And your character gained " << rewardExp << " exp!\n" << endl;
	}
	else
	{
		cout << "In the end, you could not solve the puzzle and returned to adventuring\n\n" << endl;
	}
}