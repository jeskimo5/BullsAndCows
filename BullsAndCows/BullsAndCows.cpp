// BullsAndCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"





constexpr int WORD_LENGTH = 5;
constexpr int NUM_TURNS = 10;
const std::string GUESSWORD = "crazy";
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
	FBullCowGame BCGame;
	bool CorrectWord = false;
	int turnNumber = 0;
	while (CorrectWord == false && turnNumber <= NUM_TURNS)
	{
		int numBulls = 0;
		int numCows = 0;
		std::string guess = Get_Guess_String();
		std::cout << "Your guess was: " << guess << "\n";
		CheckWord(guess, numBulls, numCows);
		InformGuessResult(numBulls, numCows);
		if (numBulls == WORD_LENGTH) {
			CorrectWord = true;
		}
		turnNumber++;
	}
	std::cout << "WOO HOO You win!";
}

//Introduce the game to the player
void GameIntro(){
	std::cout << "Welcome to Cows and Bulls\n";
	std::cout << "Please enter a " << WORD_LENGTH << " letter isogram:";
	return;
}
//get the guess from the player
std::string Get_Guess_String(){
	std::string user_guess = "";
	getline(std::cin ,user_guess);
	return user_guess;
}
void CheckWord(std::string guess,int& numBulls,int& numCows) {
	for (size_t i = 0; i < guess.length(); i++) {
		if (guess.at(i) == GUESSWORD.at(i)) {
			numBulls++;
		}
		else if (GUESSWORD.find_first_of(guess.at(i)) > -1) {
			numCows++;
					}
	}
	return;
}
void InformGuessResult(int numBulls, int numCows) {
	std::cout << "NumBulls: " << numBulls << " NumCows: " << numCows << "\n";
	return;
}
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? Y/N: ";
	std::string response = "";
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
