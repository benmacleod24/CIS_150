#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @breif Compare if the guess matches with the requested position.
 * @param position Index of the word to guess.
 * @param userGuess the users guess.
 * @param wordToGuess the word to guess.
 * @return bool
 */
bool validateGuess(int position, string userGuess, string wordToGuess) {
    return wordToGuess[position] && toupper(userGuess[0]) == toupper(wordToGuess[position]);
}

bool validateWordGuess(string guess, string wordToGuess) {
    if (guess.length() != 5) return false;
    return toupper(guess[0]) == toupper(wordToGuess[0]) && toupper(guess[1]) == toupper(wordToGuess[1]) && toupper(guess[2]) == toupper(wordToGuess[2]) && toupper(guess[3]) == toupper(wordToGuess[3]) && toupper(guess[4]) == toupper(wordToGuess[4]);
}

/**
 * @breif Display the hangman hud.
 * @param guess, all of the guesses they have gotten correct.
 * @param wordToGuess the word to guess.
 */
void printHangmanHud(bool firstGuss, bool secondGuess, bool thirdGuess, bool fourthGuess, bool fifthGuess, string wordToGuess, int numOfAttempts) {
    cout << " +--------------------------------------+" << endl;
    cout << " | ";
    cout << " Hangman  ";
    cout << "|   Attempts Left: " << numOfAttempts << "       |" << endl;
    cout << " +--------------------------------------+" << endl;
    cout << " | ";
    cout << " " << (firstGuss ? wordToGuess.substr(0, 1) : "-") << " ";
    cout << " " <<  (secondGuess ? wordToGuess.substr(1, 1) : "-") << " ";
    cout << " " << (thirdGuess ? wordToGuess.substr(2, 1) : "-") << " ";
    cout << " " << (fourthGuess ? wordToGuess.substr(3, 1) : "-") << " ";
    cout << " " << (fifthGuess ? wordToGuess.substr(4, 1) : "-") << " ";
    cout << "                      | " << endl;
    cout << " +--------------------------------------+";
    cout << endl;
}

int main()
{
    int numOfAttemptsLeft = 5;
    string wordToGuess = "GUESS";
    string wordGuessed = "";

    bool isWordGuessed = false;
    bool is1stGuessed = false;
    bool is2ndGuessed = false;
    bool is3rdGuessed = false;
    bool is4thGuessed = false;
    bool is5thGuessed = false;
    bool fullyGussed = false;

    // Round 1
    if (!isWordGuessed && numOfAttemptsLeft > 0) {

        // Clear previous entries.
        system("cls");
        
        // Display the hud to the player. 
        printHangmanHud(is1stGuessed, is2ndGuessed, is3rdGuessed, is4thGuessed, is5thGuessed, wordToGuess, numOfAttemptsLeft);
       

        // Prompt the user to enter a guess.
        cout << "  ";
        cout << "Enter a letter or word to guess: ";
        getline(cin, wordGuessed);
        // transform(wordGuessed.begin(), wordGuessed.end(), wordGuessed.begin(), ::toupper);

        // Eval weather the word was guessed or a letter was guessed.
        if (validateWordGuess(wordGuessed, wordToGuess)) {
            isWordGuessed = true;
        }
        else {
            // Validate the user input for correct guesses.
            is1stGuessed = validateGuess(0, wordGuessed, wordToGuess) || is1stGuessed;
            is2ndGuessed = validateGuess(1, wordGuessed, wordToGuess) || is2ndGuessed;
            is3rdGuessed = validateGuess(2, wordGuessed, wordToGuess) || is3rdGuessed;
            is4thGuessed = validateGuess(3, wordGuessed, wordToGuess) || is4thGuessed;
            is5thGuessed = validateGuess(4, wordGuessed, wordToGuess) || is5thGuessed;
        }

    }

    // Round 2
    fullyGussed = is1stGuessed && is2ndGuessed && is3rdGuessed && is4thGuessed && is5thGuessed;
    if (!isWordGuessed && numOfAttemptsLeft > 0 && !fullyGussed) {

        // Clear previous entries.
        system("cls");

        // Subtract one attempt.
        numOfAttemptsLeft--;

        // Display the hud to the player. 
        printHangmanHud(is1stGuessed, is2ndGuessed, is3rdGuessed, is4thGuessed, is5thGuessed, wordToGuess, numOfAttemptsLeft);


        // Prompt the user to enter a guess.
        cout << "  ";
        cout << "Enter a letter or word to guess: ";
        getline(cin, wordGuessed);
        // transform(wordGuessed.begin(), wordGuessed.end(), wordGuessed.begin(), ::toupper);

        // Eval weather the word was guessed or a letter was guessed.
        if (validateWordGuess(wordGuessed, wordToGuess)) {
            isWordGuessed = true;
        }
        else {
            // Validate the user input for correct guesses.
            is1stGuessed = validateGuess(0, wordGuessed, wordToGuess) || is1stGuessed;
            is2ndGuessed = validateGuess(1, wordGuessed, wordToGuess) || is2ndGuessed;
            is3rdGuessed = validateGuess(2, wordGuessed, wordToGuess) || is3rdGuessed;
            is4thGuessed = validateGuess(3, wordGuessed, wordToGuess) || is4thGuessed;
            is5thGuessed = validateGuess(4, wordGuessed, wordToGuess) || is5thGuessed;
        }

    }

    // Round 3
    fullyGussed = (is1stGuessed && is2ndGuessed && is3rdGuessed && is4thGuessed && is5thGuessed);
    if (!isWordGuessed && numOfAttemptsLeft > 0 && !fullyGussed) {

        // Clear previous entries.
        system("cls");

        // Subtract one attempt.
        numOfAttemptsLeft--;

        // Display the hud to the player. 
        printHangmanHud(is1stGuessed, is2ndGuessed, is3rdGuessed, is4thGuessed, is5thGuessed, wordToGuess, numOfAttemptsLeft);


        // Prompt the user to enter a guess.
        cout << "  ";
        cout << "Enter a letter or word to guess: ";
        getline(cin, wordGuessed);
        // transform(wordGuessed.begin(), wordGuessed.end(), wordGuessed.begin(), ::toupper);

        // Eval weather the word was guessed or a letter was guessed.
        if (validateWordGuess(wordGuessed, wordToGuess)) {
            isWordGuessed = true;
        }
        else {
            // Validate the user input for correct guesses.
            is1stGuessed = validateGuess(0, wordGuessed, wordToGuess) || is1stGuessed;
            is2ndGuessed = validateGuess(1, wordGuessed, wordToGuess) || is2ndGuessed;
            is3rdGuessed = validateGuess(2, wordGuessed, wordToGuess) || is3rdGuessed;
            is4thGuessed = validateGuess(3, wordGuessed, wordToGuess) || is4thGuessed;
            is5thGuessed = validateGuess(4, wordGuessed, wordToGuess) || is5thGuessed;
        }

    }

    // Round 4
    fullyGussed = (is1stGuessed && is2ndGuessed && is3rdGuessed && is4thGuessed && is5thGuessed);
    if (!isWordGuessed && numOfAttemptsLeft > 0 && !fullyGussed) {

        // Clear previous entries.
        system("cls");

        // Subtract one attempt.
        numOfAttemptsLeft--;

        // Display the hud to the player. 
        printHangmanHud(is1stGuessed, is2ndGuessed, is3rdGuessed, is4thGuessed, is5thGuessed, wordToGuess, numOfAttemptsLeft);


        // Prompt the user to enter a guess.
        cout << "  ";
        cout << "Enter a letter or word to guess: ";
        getline(cin, wordGuessed);
        // transform(wordGuessed.begin(), wordGuessed.end(), wordGuessed.begin(), ::toupper);

        // Eval weather the word was guessed or a letter was guessed.
        if (validateWordGuess(wordGuessed, wordToGuess)) {
            isWordGuessed = true;
        }
        else {
            // Validate the user input for correct guesses.
            is1stGuessed = validateGuess(0, wordGuessed, wordToGuess) || is1stGuessed;
            is2ndGuessed = validateGuess(1, wordGuessed, wordToGuess) || is2ndGuessed;
            is3rdGuessed = validateGuess(2, wordGuessed, wordToGuess) || is3rdGuessed;
            is4thGuessed = validateGuess(3, wordGuessed, wordToGuess) || is4thGuessed;
            is5thGuessed = validateGuess(4, wordGuessed, wordToGuess) || is5thGuessed;
        }

    }

    // Round 5
    fullyGussed = (is1stGuessed && is2ndGuessed && is3rdGuessed && is4thGuessed && is5thGuessed);
    if (!isWordGuessed && numOfAttemptsLeft > 0 && !fullyGussed) {

        // Clear previous entries.
        system("cls");

        // Subtract one attempt.
        numOfAttemptsLeft--;

        // Display the hud to the player. 
        printHangmanHud(is1stGuessed, is2ndGuessed, is3rdGuessed, is4thGuessed, is5thGuessed, wordToGuess, numOfAttemptsLeft);


        // Prompt the user to enter a guess.
        cout << "  ";
        cout << "Enter a letter or word to guess: ";
        getline(cin, wordGuessed);
        // transform(wordGuessed.begin(), wordGuessed.end(), wordGuessed.begin(), ::toupper);

        // Eval weather the word was guessed or a letter was guessed.
        if (validateWordGuess(wordGuessed, wordToGuess)) {
            isWordGuessed = true;
        }
        else {
            // Validate the user input for correct guesses.
            is1stGuessed = validateGuess(0, wordGuessed, wordToGuess) || is1stGuessed;
            is2ndGuessed = validateGuess(1, wordGuessed, wordToGuess) || is2ndGuessed;
            is3rdGuessed = validateGuess(2, wordGuessed, wordToGuess) || is3rdGuessed;
            is4thGuessed = validateGuess(3, wordGuessed, wordToGuess) || is4thGuessed;
            is5thGuessed = validateGuess(4, wordGuessed, wordToGuess) || is5thGuessed;
        }

    }

    /**
     * Logic to perform when the user has guessed or not the word correctly.
     */
    if (isWordGuessed || (numOfAttemptsLeft == 0 && (is1stGuessed && is2ndGuessed && is3rdGuessed && is4thGuessed && is5thGuessed))) {
        system("cls");

        cout << endl;
        cout << "Congrats! You won hangman, rerun to play again.";
        cout << endl;
    }
    else {
        system("cls");

        cout << endl;
        cout << "Dang! You lost, rerun to play again.";
        cout << endl;
    }

}

