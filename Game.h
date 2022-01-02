#pragma once
#include "Character.h"
#include <ctime>

class Game
{
public:
	Game();
	virtual ~Game();

	// Functions
	void initGame();
	void mainMenu();

	// Accessors
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	// Character related
	Character player;
};

