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

string askForName() {
    string name;

    cout << "Hello" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    return name;
}

void displayGreeting(string name) {
    cout << "Greetings " << name << "!" << endl;
}

// Entry Point
int main()
{
    const string name = askForName();
    displayGreeting(name);
}