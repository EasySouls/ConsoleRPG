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

	// Coin toss for turn
	int coinToss = rand() % 2 + 1;
	if (coinToss == 1)
		playerTurn = true;
	else 
		playerTurn = false;

	// Ending conditions
	bool escaped = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;

	// Enemies
	int nrOfEnemies = rand() % 5 + 1;
	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies.push(Enemy(character.getLevel()));
	}

	// Combat variables
	int attackRollPlayer = 0;
	int attackRollEnemy = 0;
	int defenceRoll = 0;
	int battleChoice = 0;
	int damage = 0;
	int expGained = 0;
	int playerTotal = 0;
	int enemyTotal = 0;
	int combatTotal = 0;
	
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

				cout << endl << "Choice: ";
				cin >> choice;
			}

			// Moves
			switch (choice)
			{
			case 0: // Escape
				escaped = true;
				break;

			case 1: // Attack
				cout << "Select enemy: " << endl;
				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << "[" << i << "]: Lvl " << enemies[i].getLevel() << " - Hp: " << enemies[i].getHpMax() << "/" << enemies[i].getHp() << endl;
				}
				cout << endl;
				cout << "Choice: ";
				cin >> battleChoice;

				while (cin.fail() || battleChoice >= enemies.size() || battleChoice < 0)
				{
						cout << "Wrong input! Choose again!" << endl;
						cin.clear();
						cout << "Choice: ";
						cin >> battleChoice;
				}

				// Attack roll

				combatTotal = enemies[battleChoice].getDefence() + character.getAccuracy();
				enemyTotal = (enemies[battleChoice].getDefence() / combatTotal) * 100;
				playerTotal = (character.getAccuracy() / combatTotal) * 100;
				attackRollPlayer = rand() % playerTotal;
				attackRollEnemy = rand() % enemyTotal;

				if (attackRollPlayer > attackRollEnemy) // On a hit
				{ 
					damage = character.getDamage();
					cout << "You rolled a hit (" << attackRollPlayer << ")" << endl;
					enemies[battleChoice].takeDamage(damage);
					cout << "Lvl " << enemies[battleChoice].getLevel() << " enemy has taken " << damage << " damage." << endl;
					cout << endl;

					if (!enemies[battleChoice].isAlive()) // If an enemy dies
					{
						expGained = enemies[battleChoice].getExp();
						character.gainExp(expGained);
						enemies.remove(battleChoice);
						cout << "An enemy has died." << endl;
						cout << "You have gained " << expGained << " exp." << endl;
						cout << endl;
					}
				}
				else // On a miss 
				{ 
					cout << "You rolled a miss (" << attackRollPlayer << ")" << endl;
					cout << "Lvl " << enemies[battleChoice].getLevel() << " enemy has dodged your hit." << endl;
					cout << endl;
				}
				break;

			case 2: // Defend
				break;

			case 3: // Use item
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