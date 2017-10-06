#include "FBullCowGame.h"
#include <map>
#define TMap std::map


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
	if (!IsIsogram(Guess)) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
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
	for (int32 i = 0; i < static_cast<int>(HiddenWord.length()); i++)
	{
		if (Guess[i] == HiddenWord[i])
		{
			BullCowCount.Bulls++;
		}
		else
			for (int32 j = 0; j < static_cast<int>(HiddenWord.length()); j++)
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word) // for  all the letters of the word 
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) // if the letter is in the map
		{
			return false; // we do NOT have an isogram
		}
		else
		{
			LetterSeen[Letter] = true; // Add the letter to the map as seen
		}
	}

	return true; // for example in cases where /0 is entered
}
