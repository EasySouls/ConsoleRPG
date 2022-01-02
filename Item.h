#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();

	inline string debugPrint() const { return name; };

private:
	string name;
	int sellValue;
	int buyValue;
};

