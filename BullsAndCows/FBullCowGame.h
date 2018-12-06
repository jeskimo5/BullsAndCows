#pragma once
#include <string>
using FString = std::string;
using int32 = int;

enum class EWordStatus {
	OK = 1,
	Not_Isogram = 2,
	Wrong_Length = 3,
	Not_Lowercase = 4

};

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
	EWordStatus CheckGuessValid(FString guess);
	FBullCowCount SubmitWordToGame(FString guess);
	

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool GameIsWon;
};