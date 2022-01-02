#include "Character.h"

Character::Character()
{
	xPos = 0.0;
	yPos = 0.0;

	name = "";
	level = 0;
	exp = 0;
	expNext = 0;
	
	strength = 0;
	vitality = 0;
	dexterity = 0;
	intelligence = 0;

	hp = 0;
	hpMax = 0;
	stamina = 0;
	staminaMax = 0;
	damageMin = 0;
	damageMax = 0;
	defence = 0;
	luck = 0;

	statPoints = 0;
	skillPoints = 0;
}

Character::~Character()
{

}


// Functions
void Character::initalize(std::string name)
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50 / 3) * (pow(level, 3) - 6 * pow(level, 3) + (17 * level) - 11)) + 100;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->hp = 10;
	this->hpMax = 10;
	this->stamina = 10;
	this->staminaMax = 10;
	this->damageMin = 1;
	this->damageMax = 4;
	this->defence = 1;
	this->luck = 1;

	this->statPoints = 0;
	this->skillPoints = 0;
}

void Character::printStats() const
{
	cout << "-- Character sheet --" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Level: " << this->level << endl;
	cout << "Exp: " << this->exp << endl;
	cout << "Exp to next level: " << this->expNext << endl;
	cout <<  endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Vitality: " << this->vitality << endl;
	cout << "Dexterity: " << this->dexterity << endl;
	cout << "Intelligence: " << this->intelligence << endl;
	cout  << endl;
	cout << "HP: " << this->hp << " / " << this->hpMax << endl;
	cout << "Stamina: " << this->stamina << " / " << this->staminaMax << endl;
	cout << "Damage: " << this->damageMin << " - " << this->damageMax << endl;
	cout << "Defence: " << this->defence << endl;
	cout << "Luck: " << this->luck << endl;
	cout << endl;

}

void Character::levelUp()
{
	while (exp >= expNext)
	{
		this->exp -= expNext;
		level++;
		this->expNext = static_cast<int>((50 / 3) * (pow(level, 3) - 6 * pow(level, 3) + (17 * level) - 11)) + 100;

		this->statPoints++;
		this->skillPoints++;
	}
}
