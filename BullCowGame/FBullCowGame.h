#pragma once
#include <string>



class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	void Reset(); // TODO make a more rich return value.
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string) const; // TODO make a more rich return value.



// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// See coustructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;
};
