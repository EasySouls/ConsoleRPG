#pragma once
#include "Inventory.h"
#include "Enemy.h"

using namespace std;

class Character
{
public:
	Character();
	Character(string name, int distanceTraveled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int stamina, int statPoints, int SkillPoints);
	virtual ~Character();

	// Functions
	void initalize(string name);
	void printStats() const;
	void levelUp();
	string getAsString() const;
	void updateStats();
	void addToStat(int stat, int value);

	// Accessors
	inline const int& getDistanceTraveled() const { return this->distanceTraveled; }
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getHPMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getAccuracy() const { return this->accuracy; }
	inline const int& getStatsPoints() const { return this->statPoints; }
	inline const int& getSkillPoints() const { return this->skillPoints; }
	inline const int& getStrenght() const { return this->strength; }
	inline const int& getVitality() const { return this->vitality; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getIntelligence() const { return this->intelligence; }

	// Modifiers
	inline void setDistanceTraveled(const int& distance) { this->distanceTraveled = distance; }
	inline void travel() { this->distanceTraveled++; }
	inline void gainExp(const int& exp) { this->exp += exp; }
	inline void upgradeStrenght() { this->strength++; updateStats(); }
	inline void upgradeVitality() { this->vitality++; updateStats(); }
	inline void upgradeDexterity() { this->dexterity++; updateStats(); }
	inline void upgradeIntelligence() { this->intelligence++; updateStats(); }
	inline void addSkillPoints(int num) { this->skillPoints = this->skillPoints + num; }

private:
	int distanceTraveled;

	Inventory inwentory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
	int gold;

	string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;
	
	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;
};

