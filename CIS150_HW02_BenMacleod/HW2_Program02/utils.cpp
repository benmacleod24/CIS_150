// Hangman applications for school project just starting now.
#include <iostream>

// Namespaces
using namespace std;

// Logger tool aidding in clearer code.
template <typename LogType>
void Logger(LogType log)
{
    cout << log;
}

// func to request user input with a message.
// Default res type is string can be set with generics.
template <typename ResponseType>
ResponseType RequestUserInput(string message)
{
    ResponseType returnValue;

    // Request via response via console w/ message.
    Logger(message + ": ");
    cin >> returnValue;

    return returnValue;
}