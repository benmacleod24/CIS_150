/**
 * @file main.cpp
 * @author Ben Macleod
 * @brief Sandbox for doing class work instead of new files.
 */

// Includes for libs/files
#include <iostream>
#include <string>
#include <ctime>

// Namespaces
using namespace std;

// Entry Point
int main()
{

    // Time varibles
    clock_t startedAt = clock();
    clock_t endedAt = clock();

    /* Program Starts */

    // Init Word
    string word = "";

    cout << "Enter a word: ";
    getline(cin, word);

    cout << "Word Entered: " << word << endl;

    for (int i = 0; i < word.length(); i++) {
        cout << char(word[i] - 32) << endl;
    }

    /* Program Ends */

    // Display timing metrics
    endedAt = clock();
    cout << endl << "Timing Metrics" << endl;
    cout << "Started At: " << float(startedAt) / 1000 << endl;
    cout << "Started At: " << float(endedAt) / 1000 << endl;
    cout << "Duration: " << float(endedAt - startedAt) / 1000 << endl;

}