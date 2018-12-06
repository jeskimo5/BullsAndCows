// BullsAndCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include "BullsAndCows.h"




using FText = std::string;
using int32 = int;

//Define Methods
void PlayGame();
void GameIntro();
FText Get_Guess_String();
void InformGuessResult(FText guess, int32 numBulls, int32 numCows);
bool AskToPlayAgain();


FBullCowGame BCGame;

const FText HIDDENWORD = "crazy";
int main()
{
	GameIntro();
	do
	{
		PlayGame();
	} 
	while (AskToPlayAgain());
	
	return 0;
	//play the guess back to the player
	

}
void PlayGame()
{
	BCGame.Reset();
	
	bool CorrectWord = false;
	int turnNumber = 0;
	while (!BCGame.IsGameWon()) {
		//Get the Users's Guess String
		FText guess = Get_Guess_String();
		//Have game check the guess
		if (BCGame.CheckGuessValid(guess)) {
			BCGame.SubmitWordToGame(guess);
			FBullCowGame::FBullCowCount counter = BCGame.SubmitWordToGame(guess);
			InformGuessResult(guess, counter.Bulls,counter.Cows);
		}

		// Tell the user how they did in the guess
		
		turnNumber++;
	}
	std::cout << "WOO HOO You win!";
}

//Introduce the game to the player
void GameIntro(){
	std::cout << "Welcome to Cows and Bulls\n";
	
	return;
}
//get the guess from the player
FText Get_Guess_String(){
	std::cout << "Please enter a " << BCGame.GetWordLength() << " letter isogram:";
	FText user_guess = "";
	getline(std::cin ,user_guess);
	return user_guess;
}

void InformGuessResult(FText guess, int32 numBulls, int32 numCows)
{
	std::cout << "Your guess was: " << guess << "\n";
	std::cout << "NumBulls: " << numBulls << " NumCows: " << numCows << "\n";
	return;
}
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? Y/N: ";
	FText response = "";
	getline(std::cin , response);
	bool returnVal = false;
	if (response[0] == 'Y' || response[0] =='y')
	{
		returnVal = true;
	}
	else if(response[0] == 'N' || response[0] == 'n')
	{
		returnVal = false;
	}
	else
	{
		returnVal = false;
	}
	return returnVal;
	
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
