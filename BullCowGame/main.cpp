#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
std::string GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;	// Instansiate a new game

// the entry point for our application
int main() 
{
	std::cout << BCGame.GetMaxTries();
	std::cout << BCGame.GetCurrentTry();
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
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

// get a guess from the player
std::string GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);

// return the guess back to them
	return "Your guess was: " + Guess;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int i = 0; i < MaxTries; ++i)
	{
		std::cout << GetGuess();
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return Response[0] == 'y' || Response[0] == 'Y';
}