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
	void generateEvent(Character &character, dArray<Enemy>& enemies);
	void enemyEncounter(Character &character, dArray<Enemy>& enemies);
	void puzzleEncounter(Character &character);
};

