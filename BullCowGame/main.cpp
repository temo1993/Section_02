/*
 * This is the console executable, that makes use of the BullCow class
 * This acts as the view in a MVC pattern, and is responsible for all
 * user interaction. For game logic see the FBullCowGame class.
 */
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;
using FText = std::string;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instansiate a new game

// the entry point for our application
int main()
{
	//	std::cout << BCGame.GetMaxTries();
	//	std::cout << BCGame.GetCurrentTry();
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());

	return 0; // exit the application
}

// instroduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 3;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

// get a guess from the player
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);

	// return the guess back to them
	return Guess;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop for the number of turns asking for guesses
	// TODO change from for to while loop once we are validating tries
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess();
		// std::cout << Guess; // TODO make  loop checking valid

		// Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;

		std::cout << std::endl;
		std::cout << std::endl;
	}
	// TODO summarise game
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return Response[0] == 'y' || Response[0] == 'Y';
}
