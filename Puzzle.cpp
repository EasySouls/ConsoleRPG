#include "Puzzle.h"

Puzzle::Puzzle(string fileName)
{
	ifstream inFile(fileName);

	if (inFile.is_open())
	{

	}
	inFile.close();
}

Puzzle::~Puzzle()
{
}
