#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Item
{
private:
	string name;
	int level;
	int sellValue;
	int buyValue;
	int rarity;

public:
	Item(string name = "NONE", int level = 0, int buyValue = 0, int sellVaule = 0, int rarity = 0);
	virtual ~Item();

	inline string debugPrint() const { return name; };
	virtual Item* clone() const  = 0;

	// Accessors
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getSellValue() const { return this->sellValue; }
	inline const int& getBuyValue() const { return this->buyValue; }
	inline const int& getRarity() const { return this->rarity; }


	// Modifiers

};

