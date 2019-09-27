#include <iostream>
#include <time.h>
#include <ctype.h>
using namespace std;

void printIntro() {
	cout << "Welcome to Hangman !" << endl;
	cout << "You Have to Guess Every Character of the Word To Clear the Level!!" << endl;
	cout << "The word is made of 6 characer's ,you will have 3 Lives to Guess it" << endl;
	cout << "Each Time You Guess Wrong, You will Lose a Life !! GoodLuck !!" << endl;
}

int main()
{
	printIntro();

	int life = 3;
	char wordlist[5][10] = { "animal" , "twenty" , "snitch" , "rachel" , "orange" };

	srand(time(0));
	int ran = rand() % 6;

	char userInput;
	char unknown[] = "XXXXXX";

	cout << "The Word: " << unknown << endl;

	while (life > 0) {
		cout << "Enter Your Guess: " << endl;
		cin >> userInput;

		char userGuess = tolower(userInput);
		int n = 0, l = 0;

		for (int i = 0; i < 6; i++) {
			if (userGuess == wordlist[ran][i]) {
				unknown[i] = wordlist[ran][i];
				n = n + 1;
			}
		}

		if (n > 0) {
			cout << "Correct Guess!! " << endl;
			cout << "The Word : " << unknown << endl;
			cout << "Life Remaining : " << life << endl;
		}
		else {
			cout << "Wrong Guess!! " << endl;
			life = life - 1;
			cout << "Life Remaining : " << life << endl;
		}

		for (int k = 0; k < 6; k++) {
			if (unknown[k] == 'X') {
				l = l + 1;
			}
		}

		if (l == 0) {
			cout << "Congratulation's !! You Guessed it Right" << endl;
			life = 0;
		}

	}
}
