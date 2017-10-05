#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	void Reset(); // TODO make a more rich return value.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	static bool IsGameWon();
	static bool CheckGuessValidity(FString); // TODO make a more rich return value.


	FBullCowCount SubmitGuess(FString);

	// ^^ Please try and ignore this and focus on the Interface above ^^
private:
	// See coustructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
