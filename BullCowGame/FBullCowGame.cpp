#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame(){
	Reset();
}

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString){
	return false;
}


// receives a VALID guess, increments turn, and returns counts.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;


	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();

	// temporarly code;
	int32 GuessLength = Guess.length();
	if(HiddenWordLength != GuessLength) {
		return BullCowCount;
	}
	
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// if they match then
			if (Guess[i] == MyHiddenWord[i]) {
				//if (i == j) { // if they're in the same place
				//	BullCowCount.Bulls++;// increment bulls if they're in the same place
				//}
				//else{
				//	BullCowCount.Cows++; // must be a cow;
				//}
			}
		}
	}
	return BullCowCount;
}
