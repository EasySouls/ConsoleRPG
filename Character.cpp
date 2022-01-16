#include "Character.h"

Character::Character()
{
	distanceTraveled = 0;

	gold = 0;

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
	accuracy = 0;
	luck = 0;

	statPoints = 0;
	skillPoints = 0;
}

Character::Character(string name, int distanceTraveled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int stamina, int statPoints, int skillPoints)
{
	this->distanceTraveled = distanceTraveled;

	this->gold = gold;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = statPoints;
	this->skillPoints = skillPoints;

	this->updateStats();
}

Character::~Character()
{

}


// Functions
void Character::initalize(std::string name)
{
	this->distanceTraveled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = 100;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->hp = hpMax;
	this->staminaMax = this->vitality + (this->vitality/2) + (this->dexterity/3);
	this->stamina = staminaMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + (this->level * 2);
	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = this->dexterity / 2;
	this->luck = this->intelligence;

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
	cout << "Accuracy " << this->accuracy << endl;
	cout << "Luck: " << this->luck << endl;
	cout << endl;

}

void Character::levelUp()
{
	if (exp >= expNext)
	{
		this->exp -= expNext;
		level++;
		this->expNext = (expNext * 2) + (level * 100);

		this->statPoints++;
		this->skillPoints++;

		cout << "You are now level " << this->level << ".\n" << endl;
	}
	else
	{
		cout << "Not enough exp to level up.\n" << endl;
	}
}

string Character::getAsString() const
{
	return name + " " + to_string(distanceTraveled) + " " + to_string(gold) + " " + to_string(level) + " " + to_string(exp) + " " + to_string(strength) + " " + to_string(vitality) + " " + to_string(dexterity) + " " + to_string(intelligence) + " " + to_string(hp) + " " + to_string(stamina) + " " + to_string(statPoints) + " " + to_string(skillPoints);
}

void Character::updateStats()
{
	this->expNext = (expNext * 2) + (level * 100);

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->staminaMax = this->vitality + (this->vitality / 2) + (this->dexterity / 3);
	this->damageMin = this->strength;
	this->damageMax = this->strength + (this->level * 2);
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = this->dexterity / 2;
	this->luck = this->intelligence;
}
