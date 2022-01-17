#pragma once
#include "Event.h"
#include <ctime>
#include <vector>
#include <sstream>

class Game
{
public:
	Game();
	virtual ~Game();

	// Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void levelUpCharacter();
	void saveCharacters();
	void loadCharacters();
	void Travel();

	// Accessors
	inline bool getPlaying() const { return this->playing; }

private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	vector <Character> characters;
	string fileName;
};

