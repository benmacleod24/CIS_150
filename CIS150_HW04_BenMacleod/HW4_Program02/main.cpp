// Librarys/Files imports.
#include <iostream>
#include <string>
#include <iomanip>

// Namespaces
using namespace std;

/**
 * @brief Prompt the user with instructions and options
 * @param exitCode The code to exit the program with.
 * @return string The sentence the user entered in.
 */
string promptForSentence(int exitCode) {
    string sentence = "";

    // Prompt user with basic information.
    cout << "Welcome to my program, pleas enter a sentence and select one of the options below." << endl;
    cout << "Enter \"" << exitCode << "\" to exit the program." << endl;
    cout << "===================================================================================" << endl;

    // Display List of options for user.
    cout << "1. Display the middle character, if there is one." << endl;
    cout << "2. Convert to uppercase." << endl;
    cout << "3. Convert to lowercase." << endl;
    cout << "4. Display backwards." << endl;

    // Ask user for sentence.
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Return the sentence the user entered.
    cout << endl;
    return sentence;
}

/**
 * @brief Generate header for selection responses.
 * @param sentence The sentence that was enterted by the user.
 */
void generateResponseHeading(string sentence) {
    const int LENGTH = sentence.length();
    const int SPACING_INTERVAL = 3;
    const int BORDER_LENGHT = LENGTH + (SPACING_INTERVAL * 2);

    // Apply spacing to word.
    cout << setw(LENGTH + SPACING_INTERVAL);
    cout << sentence;
    cout << setw(0) << endl;

    // Loop through border length.
    for (int i = 0; i < BORDER_LENGHT; i++) {
        cout << "=";
    }

    cout << endl;
}

/**
 * @brief Get the middle character of a string.
 * @param sentence String to get the middle character of.
 */
void getMiddleCharacter(string sentence) {
    // Get the lenght and incremeant it by one for math reasons.
    const int LENGTH = sentence.length() + 1;
    const bool hasMiddleCharacter = (LENGTH / 2) % 2 == 0;
    // Subtract one since we added one for math reasons.
    const int middleCharacterIndex = (LENGTH / 2) - 1;

    // Generate selection response header.
    generateResponseHeading(sentence);

    // If there is not middle display that there isn't one.
    if (hasMiddleCharacter) {
        cout << "There is no middle" << endl;
    } else {
        // Display middle character, subtract one since we added one.
        cout << "Middle character is: " << sentence[middleCharacterIndex] << endl;
    }

    cout << endl;
}

/**
 * @brief Convert a string to uppercase or lowercase.
 * @param sentence The string to convert.
 * @param toUpper If true it will convert to uppercase, if false it will convert to lowercase.
 */
void convertSentence(string sentence, bool toUpper) {

    // Generate selection response.
    generateResponseHeading(sentence);

    // Loop through string characters.
    for (int i = 0; i < sentence.length(); i++) {
        const char letter = sentence[i];
        const bool isUppercase = letter >= 65 && letter <= 90;
        const bool isLowercase = letter >= 97 && letter <= 121;

        // If converting to upper and it is lowercase alphabetic convert it.
        if (toUpper && isLowercase) {
            cout << static_cast<char>(letter - 32);
        } else if (!toUpper && isUppercase) {
            cout << static_cast<char>(letter - 32);
        } else {
            cout << letter;
        }

    }

    cout << endl;
}

void displaySentenceBackwards(string sentence) {
    generateResponseHeading(sentence);
    for (int i = sentence.length(); i >= 0; i--) {
        cout << sentence[i];
    }
    cout << endl;
}

int promptForSelection(string sentence, int EXIT_CODE) {
    int selection = 0;

    cout << "Selection: ";
    cin >> selection;
    cout << endl;

    // If exit code was entered return function.
    if (selection == EXIT_CODE) return selection;

    // While selection is not in the range of 1 & 4 ask for selection.
    while (selection > 4 || selection < 1) {
        // Ask user for selection
        cout << "Invalid Input, please try again. Selection: ";
        cin >> selection;

        // If exit code was entered return function.
        if (selection == EXIT_CODE) return selection;
    }

    switch (selection) {
        case 1:
            getMiddleCharacter(sentence);
            break;
        case 2:
            convertSentence(sentence, true);
            break;
        case 3:
            convertSentence(sentence, false);
            break;
        case 4:
            displaySentenceBackwards(sentence);
            break;
        default:
            return 0;
    }

    promptForSelection(sentence, EXIT_CODE);
}

// Entry Point for project.
int main() {

    const int EXIT_CODE = -999;
    string sentence;
    int selection = 0;

    // Prompt user for sentence.
    sentence = promptForSentence(EXIT_CODE);
    promptForSelection(sentence, EXIT_CODE);
}