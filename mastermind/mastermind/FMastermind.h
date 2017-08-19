#pragma once

#include <string>

class FMastermind
{
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool GameWon();
	bool IsGuessValid(std::string);

private:
	int myCurrentTry;
	int myMaxTries;

};
