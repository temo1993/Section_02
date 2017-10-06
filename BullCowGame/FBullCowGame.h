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

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	void Reset(); // TODO make a more rich return value.

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	EGuessStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;


	FBullCowCount SubmitValidGuess(FString);

	// ^^ Please try and ignore this and focus on the Interface above ^^
private:
	// See coustructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
};
