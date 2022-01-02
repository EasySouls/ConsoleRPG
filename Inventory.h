#pragma once

#include "Item.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void addItem(const Item &item);
	void removeItem(int index);
	inline void debugPrint() const 
	{
		for (size_t i = 0; i < nrOfItems; i++)
		{
			cout << itemArr[i]->debugPrint() << endl;
		}
	}

private:
	void expand();
	void initialize(const int from);
	int cap;
	int nrOfItems;
	Item **itemArr;
};

