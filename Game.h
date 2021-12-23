#pragma once
#include "Character.h"
#include <ctime>

class Game
{
public:
	Game();
	virtual ~Game();

	// Functions
	void InitGame();
	void MainMenu();

	// Accessors
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	// Character related
	Character player;
};

