/**
 * @file main.cpp
 * @author Ben Macleod
 * @brief Change calculator, determine the fewest amount of bills
 *  to be returned based off a dollar value.
 * @date 2022-09-12
 */

// Includes libs/files.
#include <iostream>
#include "utils.cpp"

// Namespaces.
using namespace std;

// Entry point for the application.
int main()
{
    int inputDollarAmount = 0;
    int decrementalChange = 0;

    /**
     * Keeps track of how many bills to give back per change.
     * Ideally this would be an object, but can't use them.
     */
    int twenties = 0;
    int tens = 0;
    int fives = 0;
    int ones = 0;

    /**
     * Request the user input for the dollar amount.
     * `decrementChange` gets passed the same value and becomes the calculation varible.
     */
    inputDollarAmount = RequestUserInput<int>("Enter a dollar amount");
    decrementalChange = inputDollarAmount;

    /**
     * Each bill calculation takes the exisiting decrementalChange and divides it's assigned
     * and then sets the new decremental change so we can keep track of how much change is left to give.
     */

    // $20 bills.
    twenties = decrementalChange / 20;
    decrementalChange = decrementalChange - (twenties * 20);

    // $10 bills.
    tens = decrementalChange / 10;
    decrementalChange = decrementalChange - (10 * tens);

    // $5 bills.
    fives = decrementalChange / 5;
    decrementalChange = decrementalChange - (5 * fives);

    // $1 bills.
    ones = decrementalChange / 1;
    decrementalChange = decrementalChange - (1 * ones);

    // Log out the information.
    Logger("\nThe fewest number of bills to get $"+ to_string(inputDollarAmount) + " is:\n");
    Logger("=====================\n");
    Logger("$20 bills: " + to_string(twenties) + "\n");
    Logger("$10 bills: " + to_string(tens) + "\n");
    Logger(" $5 bills: " + to_string(fives) + "\n");
    Logger(" $1 bills: " + to_string(ones) + "\n\n");
}