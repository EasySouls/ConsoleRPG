#pragma once
#include "Event.h"
#include <ctime>
#include <vector>
#include <sstream>

class Game
{
private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	vector <Character> characters;
	string fileName;

	// Enemies
	dArray<Enemy> enemies;

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
	void selectCharacter();
	void Travel();

	// Accessors
	inline bool getPlaying() const { return this->playing; }
};

