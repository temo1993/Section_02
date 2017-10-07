/*
 * This is the console executable, that makes use of the BullCow class
 * This acts as the view in a MVC pattern, and is responsible for all
 * user interaction. For game logic see the FBullCowGame class.
 */
#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make syntax Unreal friendly
using int32 = int;
using FText = std::string;

// Function prototypes as outside a class
void PrintIntro();
FText GetValidGuess();
void PlayGame();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instansiate a new game, which we re-use across plays

// the entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());

	return 0;
}

void PrintIntro()
{
	std::cout << "             .=     ,      =. \n";
	std::cout << "     _  _   /'/   )\\,/,/(_ \\ \\    \n";
	std::cout << "      `//-.| ( ,\\\\)\\//\\)\\/_)  | \n";
	std::cout << "      //___\\ `\\\\\\/\\\\/\\/\\\\///' / \n";
	std::cout << "   , -'~`-._ `'--'_   `'''`  _ \\`''~-,_ \n";
	std::cout << "   \\       `-.  '_`.      .'_` \\ , -'~`/ \n";
	std::cout << "    `.__. - '`/ (-\\        /-) |-.__,' \n";
	std::cout << "       ||   |   \\O)   / ^\\ (O /  | \n";
	std::cout << "      `\\\\   |        /   `\\     / \n";
	std::cout << "        \\\\  \\       /      `\\  / \n";
	std::cout << "         `\\\\ `-.   /' .---.--.\\ \n";
	std::cout << "           `\\\\ / `~(, '()      (' \n";
	std::cout << "              (O) \\\\ _, . - ., _) \n";
	std::cout << "              \\\\ `\\'`          / \n";
	std::cout << "                     ''`''''~'` \n";
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

// loop continiously until user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
		default:
			// Assuming the guess is VALID.
			break;
		}
	}
	while (Status != EGuessStatus::OK); // Keep looping until we got no errors.
	return Guess;
}

// Plays a single gmae to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return Response[0] == 'y' || Response[0] == 'Y';
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WON!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
