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
	bool escaped = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	
	while (!escaped && !playerDefeated && !enemyDefeated)
	{

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