#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = MAX_TRIES;

	MyMaxTries = 8;

	const FString HIDDEN_WORD = "planet";
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


	// loop through all letters in the guess

	const int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// if they match then
			if (Guess[i] == MyHiddenWord[i])
			{
				// if they're in the same place
				if (i == j)
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				// else
				else
				{
					// increment cows
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
