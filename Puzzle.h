#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Puzzle
{
private:
	string question;
	vector<string> answers;
	int correctAnswer;

public:
	Puzzle(string fileName);
	virtual ~Puzzle();
	string getAsString();

	inline const int& getCorrectAns() const { return this->correctAnswer; }
};

