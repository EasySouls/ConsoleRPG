#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;
	this->damageMin = this->level * 4;
	this->damageMax = this->level * 5;
	this->dropChance = rand() % 100;
	this->defence = rand() % 10;
	this->accuracy = rand() % 100;
}

Enemy::~Enemy()
{

}

void Enemy::takeDamage(int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
		//enemy dies
	}
}

string Enemy::getAsString() const
{
	return "Level: " + to_string(this->level) + "\n" + "Hp: " + to_string(this->hp) + " / " + to_string(this->hpMax) + "\n" + "Damage: " + to_string(damageMin) + " - " + to_string(damageMax) + "\n" + "Defence: " + to_string(this->defence) + "\n" + "Accuracy: " + to_string(this->accuracy) + "\n" + "Drop chance: " + to_string(this->dropChance) + "\n";
}

