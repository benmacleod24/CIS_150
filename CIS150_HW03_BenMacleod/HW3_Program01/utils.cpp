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

/**
 * @brief Request user input with a message.
 * @param message Message to be displayed when prompted.
 * @return The response weather it is a string or not.
 */
string RequestInput(string message)
{
    string inputResponse = "";

    // Prompt for response.
    cout << message << ": ";
    getline(cin, inputResponse);

    return inputResponse;
}

/**
 * @brief Wrapper for better getLine method.
 * @deprecated
 */
template <typename ResponseType>
string RequestUserInput(string message)
{
    return RequestInput(message);
}
