#include "Inventory.h"

Inventory::Inventory()
{
	this->cap = 5;
	this->nrOfItems = 0;
	this->itemArr = new Item * [cap];
	this->initialize();
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

Inventory::Inventory(const Inventory& obj)
{
	this->cap = obj.cap;
	this->nrOfItems = obj.nrOfItems;
	this->itemArr = new Item * [this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->nrOfItems);
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->nrOfItems)
		throw("BAD INDEX!");

	return *this->itemArr[index];
}

void Inventory::addItem(const Item& item)
{
	if (this->nrOfItems >= this->cap) 
	{
		expand();
	}
	this->itemArr[this->nrOfItems++] = item.clone();
}

void Inventory::expand()
{
	this->cap *= 2;
	Item** tempArr = new Item * [cap];

	for (size_t i = 0; i < nrOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	delete[] itemArr;
	this->itemArr = tempArr;
	initialize(nrOfItems);
}

void Inventory::removeItem(int index)
{

}


