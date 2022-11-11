#include <iostream>
#include <string>

using namespace std;

bool isUppercase(char letter) {
    return letter >= 65 && letter <= 90;
}

string toUpper(string word) {
    string transformed = word;

    // Loop through word and determine if it is a uppercase.
    for (int i = 0; i < word.length(); i++) {
        const bool _isUppercase = isUppercase(word[i]);
        const bool isLetter = (word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122);

        // If the letter is not uppercase subtract 32 from ascii char.
        if (!_isUppercase && isLetter) {
            transformed.at(i) = word[i] - 32;
        }
    }

    return transformed;
}

int main()
{
    const int MAX_NUM_ATTEMPTS = 5;

    int wordAttempts = 0;
    int letterAttempts = 0;

    string displayLiteral = "";
    string wordToGuess;
    string wordGuessed;

    bool isWordGuessed = toUpper(displayLiteral) == toUpper(wordToGuess);

    /*
     * @todo Ask if .empty() is okay to use.
     */
    while (wordToGuess == "" || wordToGuess.empty()) {
        cout << "Insert a word for player two to guess: ";
        getline(cin, wordToGuess);
        // Convert word to all uppercase.
        wordToGuess = toUpper(wordToGuess);
    }

    // Transform display literal for dashes.
    for (int i = 0; i < wordToGuess.length(); i++) {
        displayLiteral = displayLiteral + "-";
    }

    // While the word is not guessed and there are attempts left loop through guess logic.
    while (toUpper(displayLiteral) != wordToGuess && letterAttempts < MAX_NUM_ATTEMPTS && wordAttempts < MAX_NUM_ATTEMPTS) {

        system("cls");

        // Print word.
        cout << displayLiteral << endl;

        // Request letter input from user.
        cout << "You have " << (MAX_NUM_ATTEMPTS - letterAttempts) << " guesses left. Guess a letter: ";
        getline(cin, wordGuessed);

        // Check input and make sure it's a letter.
        while (wordGuessed.length() > 1) {
            cout << "You did not enter a letter! Try again: ";
            getline(cin, wordGuessed);
        }

        string guessResponseString = "";

        // Check for correct guesses in the word to guess.
        for (int i = 0; i < wordToGuess.length(); i++) {
            if (wordToGuess[i] == toUpper(wordGuessed)[0]) {
                displayLiteral.at(i) = wordGuessed[0];
                guessResponseString = guessResponseString + " and " + to_string(i);
            }
        }

        // Display guess response message.
        !guessResponseString.empty() && cout << "You guessed the letters at position(s)" << guessResponseString << " correct" << endl;

        // Add a letter attempt.
        letterAttempts++;

        if (toUpper(displayLiteral) != wordToGuess) {
            // Display current guesses.
            cout << endl << displayLiteral << endl;

            // Ask for a word from the user.
            cout << "You have " << (MAX_NUM_ATTEMPTS - wordAttempts) << " guesses left. Guess a word: ";
            getline(cin, wordGuessed);

            // If the words match the set varibles to break the loop.
            if (toUpper(wordGuessed) == wordToGuess) {
                displayLiteral = toUpper(wordGuessed);
                wordAttempts = MAX_NUM_ATTEMPTS;
                letterAttempts = MAX_NUM_ATTEMPTS;
            }

            // Add word attempt.
            wordAttempts++;
        }
    }

    cout << endl;

    if (toUpper(displayLiteral) == toUpper(wordToGuess)) {
        cout << "You win!! You guessed the word right in " << (wordAttempts) << " guesses.";
    }
    else {
        cout << "Sorry you lost! The word was: " << wordToGuess << endl;
    }
}