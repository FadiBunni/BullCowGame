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

int32 FBullCowGame::GetHiddenWordLength() const{
	return MyHiddenWord.length();
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ant";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const {
	return EWordStatus::OK;
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
	
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
