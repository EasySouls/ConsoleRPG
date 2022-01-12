#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Puzzle
{
private:
	string question;
	vector<string> answers;
	int corectAnswer;

public:
	Puzzle(string fileName);
	virtual ~Puzzle();
};

