#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;

	MyCurrentTry = MAX_TRIES;
	MyMaxTries = 8;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) const
{
	return false;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}
