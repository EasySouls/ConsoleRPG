#include "Inventory.h"

Inventory::Inventory()
{
	this->cap = 10;
	this->nrOfItems = 0;
	this->itemArr = new Item * [cap];

}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (this->nrOfItems >= this->cap) 
	{
		expand();
	}
	this->itemArr[this->nrOfItems++] = new Item(item);
}

void Inventory::expand()
{
	this->cap *= 2;
	Item** tempArr = new Item * [cap];

	for (size_t i = 0; i < nrOfItems; i++)
	{
		tempArr[i] = new Item(*itemArr[i]);
	}

	for (size_t i = 0; i < nrOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
	this->itemArr = tempArr;
	initialize(nrOfItems);
}

void Inventory::removeItem(int index)
{

}


