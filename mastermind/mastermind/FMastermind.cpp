#include "stdafx.h"
#include "FMastermind.h"

void FMastermind::Reset()
{	
	constexpr int32 MAX_TRIES = 8;
	
	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "rgbyo";
	secretWord = HIDDEN_WORD;
	bGameIsWon = false;

	return;
}

FMastermind::FMastermind()
{
	Reset();
}

int32 FMastermind::GetMaxTries() const
{
	return myMaxTries;
}

int32 FMastermind::GetCurrentTry() const
{
	return myCurrentTry;
}

int32 FMastermind::GetHiddenWordLength() const
{	
	return secretWord.length();
}

bool FMastermind::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FMastermind::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::NOT_LOWERCASE;
	} 
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::WRONG_LENGTH;
	}
	else {
		return EGuessStatus::OK;
	}
}

FredWhiteCount FMastermind::SubmitValidGuess(FString Guess)
{	
	//increment the turn number
	myCurrentTry++;

	//set up a return variable
	FredWhiteCount redWhiteCount;
	int32 secreatWordLength = secretWord.length();

	for (int32 i = 0; i < secreatWordLength; i++) {
		for (int32 j = 0; j < secreatWordLength; j++) {
			if (Guess[i] == secretWord[j]) {
				if (i == j) {
					redWhiteCount.Reds++;
				}
				else {
					redWhiteCount.Whites++;
				}
			}
		}
	}
	if (redWhiteCount.Reds == secreatWordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return redWhiteCount;
}

bool FMastermind::IsIsogram(FString Word) const
{	
	if (Word.length() <= 1) { return true; }
	//Setting up the map
	TMap<char, bool> LetterSeen;

	//auto cause dont really care about the type coming in
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false; //no repetition
		}
		else { //other wise add letter to map
			LetterSeen[Letter] = true;
		}
	}
	
	return true;
}

bool FMastermind::IsLowercase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
