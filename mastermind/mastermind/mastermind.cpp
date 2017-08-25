// mastermind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
//header file
#include "FMastermind.h"


using FText = std::string;
using int32 = int;

void gameIntro();

void playGame();

FText getValidGuess();

FText printGuess(FText Guess);

bool playAgain();

void PrintGameSummary();

//game instance
FMastermind MastermindGame;



int main()
{	
	std::cout<<MastermindGame.GetCurrentTry();

	bool bWantsToPlayAgain;
 
	do {
		gameIntro();

		playGame();

		bWantsToPlayAgain = playAgain();

	} while (bWantsToPlayAgain);
	
	return 0;
}


//game intro and initial setup
void gameIntro() 
{
	
	

	std::cout << std::endl;
	std::cout << "Welcome to Mastermind!! A fun yet challenging command-line game." << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the colour combination consisting of " << MastermindGame.GetHiddenWordLength() << " colours that I am thinking of?";
	std::cout << "You can input r(red), g(green), b(blue), y(yellow), p(pink), o(orange), s(silver), w(white)" << std::endl;

	return;
}


void playGame()
{
	
	int32 maxTries = MastermindGame.GetMaxTries();
	

	constexpr int32 MAX_GUESSES = 12;

	while (!MastermindGame.IsGameWon() && MastermindGame.GetCurrentTry() <= maxTries) {
		FText Guess = getValidGuess(); //TODO check if guess is valid

		FredWhiteCount redWhiteCount = MastermindGame.SubmitValidGuess(Guess);

		std::cout << "Red = " << redWhiteCount.Reds;
		std::cout << "| White = " << redWhiteCount.Whites << std::endl;
		std::cout << std::endl;
	}
	PrintGameSummary();
	

}


//user input for guess
FText getValidGuess()
{	
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		int32 currentTry = MastermindGame.GetCurrentTry();
		FText Guess = "";
		std::cout << std::endl;
		std::cout << "Try " << currentTry << ". Please enter your guess: ";
		getline(std::cin, Guess);

		//Checking if valid
		Status = MastermindGame.CheckGuessValidity(Guess);

		switch (Status)
		{

		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Your word length is incorrect. Please try again. " << std::endl;
			break;

		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please recheck the characters you entered. You cannot have repeating colors " << std::endl;
			break;

		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "Please input a guess that is all lowercase " << std::endl;
			break;

		default:
			return Guess;
		}
	} while (Status != EGuessStatus::OK);

}

void PrintGameSummary() {
	if (MastermindGame.IsGameWon()) {
		std::cout << "CONGRATULATION! YOU BEAT THIS GAME!!!" << std::endl;
	}
	else {
		std::cout << "BETTER LUCK NEXT TIME!" << std::endl;
	}
}



//ask if user wants to play again
bool playAgain() 
{
	MastermindGame.Reset();
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');

}

