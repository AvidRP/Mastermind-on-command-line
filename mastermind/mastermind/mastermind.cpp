// mastermind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>



void gameIntro();

void playGame();

std::string getGuess();

std::string printGuess(std::string Guess);

bool playAgain();



int main()
{	

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
	
	constexpr int COLOR_LENGTH = 5;

	std::cout << std::endl;
	std::cout << "Welcome to Mastermind!! A fun yet challenging command-line game." << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the colour combination consisting of " << COLOR_LENGTH << " colours that I am thinking of?" << std::endl;

	return;
}


void playGame()
{
	constexpr int MAX_GUESSES = 12;

	for (int i = 0; i < MAX_GUESSES; i++) {
		getGuess();
	}
}


//user input for guess
std::string getGuess()
{
	
	std::string Guess = "";
	std::cout << std::endl;
	std::cout << "Please enter your guess: ";
	getline(std::cin, Guess);
	
	printGuess(Guess);

	return Guess;
}


//print back the guess
std::string printGuess(std::string Guess) 
{

	//print the user input
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;

	return Guess;
}

//ask if user wants to play again
bool playAgain() 
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');

}

