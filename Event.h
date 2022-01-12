#pragma once
#include <stdlib.h>
#include "Puzzle.h"
#include "Character.h"

class Event
{
private:
	int nrOfEvents;
public:
	Event();
	virtual ~Event();
	void generateEvent(Character &character);
	void enemyEncounter(Character &character);
	void puzzleEncounter(Character &character);
};

