#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

// Receives a VALID guess, inscrements turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	FString HiddenWord = MyHiddenWord;

	// loops through all letters in the guess and hidden word 
	// and comparing them with each other
	for (int32 i = 0; i < HiddenWord.length(); i++)
	{
		if (Guess[i] == HiddenWord[i])
		{
			BullCowCount.Bulls++;
			HiddenWord.erase(0, 1);
			Guess.erase(0, 1);
			i--;
		}
		else
			for (int32 j = 0; j < HiddenWord.length(); j++)
			{
				if (Guess[i] == HiddenWord[j])
				{
					BullCowCount.Cows++;
				}
			}
	}
	if (BullCowCount.Bulls == MyHiddenWord.length())
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
