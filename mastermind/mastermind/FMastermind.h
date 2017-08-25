#pragma once

#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

struct FredWhiteCount
{
	int32 Whites = 0; 
	int32 Reds = 0;
};

enum class EGuessStatus
{
	Invalid, OK, NOT_ISOGRAM, WRONG_LENGTH, NOT_LOWERCASE
};

class FMastermind
{
public:
	FMastermind();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	void Reset();
	EGuessStatus CheckGuessValidity(FString) const;
	//cout red and white and increase turn #
	FredWhiteCount SubmitValidGuess(FString);

private:
	int32 myCurrentTry;
	int32 myMaxTries;
	FString secretWord;
	bool bGameIsWon;
	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;
};
