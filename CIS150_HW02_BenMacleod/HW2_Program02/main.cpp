/**
 * @file main.cpp
 * @author Ben Macleod
 * @brief Determine the index of a users favorite city.
 * @date 2022-09-12
 */

// Include libs/files.
#include <iostream>
#include <string>
#include "utils.cpp"

// Namespaces.
using namespace std;

// Entry point for the application
int main() 
{
    string userCityInput = "";
    int userStringIndex = 0;
    string inputCityWithoutSpaces;

    /**
     * Request users favorite city.
     * found std::getLine will pretty much take every character in the input and transform it in a string.
     */
    Logger("Input your favorite city: ");
    getline(cin, userCityInput);

    // Request index of the character the user wants to see.
    userStringIndex = RequestUserInput<int>("Which character would you like to display");

    /**
     * Removing all spaces from a string, we are not replacing the space.
     * Still need to look into the std::erase and std::remove_if and see exactly how it works
     * url: https://cplusplus.com/reference/algorithm/remove_if/
     */
    inputCityWithoutSpaces = userCityInput;
    inputCityWithoutSpaces.erase(remove_if(inputCityWithoutSpaces.begin(), inputCityWithoutSpaces.end(), ::isspace), inputCityWithoutSpaces.end());

    Logger("\n");
    Logger("The user entered: " + userCityInput + "\n");
    Logger("The character at position " + to_string(userStringIndex) + " is: " + inputCityWithoutSpaces[userStringIndex]);
    Logger("\n");
    
}