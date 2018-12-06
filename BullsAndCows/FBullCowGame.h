#pragma once
#include <string>
using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	struct FBullCowCount {
		int32 Bulls = 0;
		int32 Cows = 0;
	};
	FBullCowGame();
	void Reset(); //TODO make a more rich return value
	int32 GetWordLength() const;
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValid(FString guess);
	FBullCowCount SubmitWordToGame(FString guess);
	

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool GameIsWon;
};