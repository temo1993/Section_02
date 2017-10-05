#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

// Receives a VALID guess, inscrements turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	FString HiddenWord = MyHiddenWord;

	// loop through all letters in the guess


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
	return BullCowCount;
}
