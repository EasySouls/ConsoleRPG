#pragma once
#include <stdlib.h>
#include <string>
#include"dArray.h"
using namespace std;

class Enemy
{
private:
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	float dropChance;
	int defence;
	int accuracy;

public:
	Enemy(int level = 1);
	virtual ~Enemy();

	inline bool isAlive() { return this->hp > 0; }
	string getAsString() const;
	void takeDamage(int damage);

	inline int getDamage() { return rand() % this->damageMax + this->damageMin; };
	inline int getExp() const { return this->level * 100; }
	inline int getHp() const { return this->hp; }
	inline int getHpMax() const { return this->hpMax; }
	inline int getLevel() const { return this->level; }
	//inline string getName() const { return this->name; }
	inline int getDefence() const { return this->defence; }
	inline int getAccuracy() const { return this->accuracy; }
};

