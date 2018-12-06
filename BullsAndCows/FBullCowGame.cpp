#include "pch.h"
#include "FBullCowGame.h"


constexpr int NUM_TURNS = 10;
const std::string HIDDENWORD = "crazy";

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyMaxTries = 6;
	MyCurrentTry = 1;
	GameIsWon = false;
	return;
}

int32 FBullCowGame::GetWordLength() const
{
	return HIDDENWORD.length();
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}


bool FBullCowGame::IsGameWon() const
{
	return GameIsWon;
}
EWordStatus FBullCowGame::CheckGuessValid(FString guess)
{
	if (guess.length() != HIDDENWORD.length()) {
		return EWordStatus::Wrong_Length;
	}
	else if (false) {
		return EWordStatus::Not_Isogram;
	}
	else if (false)
	{
		return EWordStatus::Not_Lowercase;
	}
	else 
	{
		return EWordStatus::OK;
	}
}

FBullCowGame::FBullCowCount FBullCowGame::SubmitWordToGame(FString Guess)
{
	FBullCowCount counter;
	// for each letter in the guess
	for (size_t i = 0; i < Guess.length(); i++) {
		//is the letter in the right spot?
		if (Guess.at(i) == HIDDENWORD.at(i)) {
			counter.Bulls++;
		}
		//or is the letter contained in the word at all?
		else if (HIDDENWORD.find_first_of(Guess.at(i)) > -1) {
			counter.Cows++;
		}
	}
	if (counter.Bulls == Guess.length()) {
		GameIsWon = true;
	}
	return counter;

}
