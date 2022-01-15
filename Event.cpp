#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character)
{
	int i = rand() % this->nrOfEvents;

	switch (i)
	{
	case 0:
		// Enemy encounter
		enemyEncounter(character);
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
void Event::enemyEncounter(Character& character)
{
	//while()
}

void Event::puzzleEncounter(Character& character)
{
	cin.ignore();
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	Puzzle puzzle("Puzzles/p1.txt"); 

	while (!completed && chances > 0)
	{
		chances--;
		cout << puzzle.getAsString() << endl;

		cout << "\nYour answer: ";
		cin >> userAns;
		cout << "\n";

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;
			//GIVE USER EXP ETC AND CONTINUE
		}
	}
	if (completed)
	{
		cout << "You succeeded in solving the puzzle.\n" << endl;
	}
	else
	{
		cout << "In the end, you could not solve the puzzle and returned to adventuring\n" << endl;
	}
}