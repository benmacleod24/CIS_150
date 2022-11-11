#include <iostream>
#include <math.h>

using namespace std;

/**
 * @brief Display the menu options to the user, does not collect
 * any response data from the user.
 */
void displayMenu() {
    system("clear");
    cout << "  Math Application  " << endl;
    cout << "====================" << endl;
    cout << "1.) Addition" << endl;
    cout << "2.) Subtraction" << endl;
    cout << "3.) Multiplication" << endl;
    cout << "4.) Division" << endl;
    cout << "5.) Absolute Value" << endl << endl;
}

/**
 * @brief Collect a menu selection from the user, 
 * handles error checking to make sure option is in menu range.
 * 
 * @return Menu selection.
 */
int requestMenuOption(bool fromError = false) {
    int option = 0;

    // Display the menu options for the user here, because this will be needed multiple times.
    if (!fromError) displayMenu();

    // ask the user to make a selection from above.
    cout << "Please make a selection from the choices above: ";
    cin >> option;

    if(option < 1 || option > 5) {
        // Display menu again.
        displayMenu();

        // Tell the user to try again.
        cout << "Invalid Input, try again!" << endl;
        requestMenuOption(true);
    }

    return option;
}

/**
 * @brief Display the results of the operation performed.
 * 
 * @tparam Type of numbers in the params.
 * @param type The type of operation performed.
 * @param result The results of the function
 * @param valueOne Value one of the operation.
 * @param valueTwo Value two of the operation.
 */
template <typename NumberType = double>
void displayResultsToUser(int type, NumberType result, NumberType valueOne, NumberType valueTwo) {

    // Determine logic based off operation type.
    switch (type)
    {
    case 1:
        cout << valueOne << " + " << valueTwo << " = " << result;
        break;
    case 2:
        cout << valueOne << " - " << valueTwo << " = " << result;
        break;
    case 3:
        cout << valueOne << " * " << valueTwo << " = " << result;
        break;
    case 4:
        if (result == -9999) {
            cout << "[Error] You can not divide by zero.";
        } else {
            cout << valueOne << " / " << valueTwo << " = " << result; 
        }
    
        break;
    case 5:
        cout << "|" << valueOne << "|" << " = " << result;
        break;     
    default:
        break;
    }

    cout << endl;
}

/**
 * @brief Ask the user if they want to run the application again.
 * 
 * @return true 
 * @return false 
 */
bool askToRunAgain() {
    int response = 0;
    bool shouldRunAgain = true;

    // Ask if they would like to run again.
    cout << "Would you like to run again? (1 = Yes OR 2 = No): ";
    cin >> response;
    cout << endl;

    // If the response is not valid recurse function to try again.
    if (response > 2 || response < 1) {
        system("clear");
        cout << endl << "Invalid input, please try again." << endl;
        askToRunAgain();
    }

    // Determine if we should run again based off response.
    if (response == 1) shouldRunAgain = true;
    if (response == 2) shouldRunAgain = false;

    return shouldRunAgain;
}

/**
 * @brief Add two values.
 * 
 * @tparam NumberType This should always be a number/deciaml type, defaults to double.
 * @param valueOne Value one to be added.
 * @param valueTwo Value two to be added.
 * @return The sum of the addition.
 */
template <typename NumberType = double>
double addition(double valueOne, double valueTwo) {
    if (!valueOne || !valueTwo) return 0.0;
    return valueOne + valueTwo;
}

/**
 * @brief Subtract two values.
 * 
 * @tparam NumberType This should always be a number/deciaml type, defaults to double.
 * @param valueOne Value one to be subtracted.
 * @param valueTwo Value two to be subtracted.
 * @return The difference in the subtraction.
 */
template <typename NumberType = double>
double subtraction(double valueOne, double valueTwo) {
    if (!valueOne || !valueTwo) return 0.0;
    return valueOne - valueTwo;
}

/**
 * @brief Multiply two values together.
 *
 * @tparam NumberType This should always be a number/deciaml type, defaults to double.
 * @param valueOne First value to multiply with.
 * @param valueTwo Second value to multiply with.
 * @return The product of the multiplication.
 */
template <typename NumberType = double>
double multiply(double valueOne, double valueTwo) {
    if (!valueOne || !valueTwo) return 0.0;
    return valueOne * valueTwo;
}

/**
 * @brief Divide two value together/
 * 
 * @tparam NumberType This should always be a number/deciaml type, defaults to double.
 * @param valueOne The value to be divded by.
 * @param valueTwo The divisor.
 * @return The quotient of the expression.
 */
template <typename NumberType = double>
NumberType divide(NumberType valueOne, NumberType valueTwo) {
    if (valueTwo == 0 || valueTwo == 0.0) return -9999;
    return valueOne / valueTwo;
}

/**
 * @brief Get the absolute value of a number.
 * 
 * @tparam NumberType This should always be a number/deciaml type, defaults to double.
 * @param value Value to get the absolute value of.
 * @return The absoulte value.
 */
template <typename NumberType = double>
NumberType absoulte(NumberType value) {
    // If our value is negitive get it's positive counter part.
    if (value < 0) value =- value;
    return value;
}

/**
 * @brief Entry point for the application. 
 */
int main() {
    // Collect menu selection from the user, with error checking.
    const int menuSelection = requestMenuOption();

    // Operation Varibles.
    double results;
    double valueOne = 0;
    double valueTwo = 0;

    // Collect first number from user.
    cout << "Enter a number: ";
    cin >> valueOne;

    // If the menu selection is absolute value make a new line after.
    if (menuSelection == 5) cout << endl;

    // Collect the second number for operations that require it.
    // If the menu selection is absolute value then don't ask for it again.
    if (menuSelection != 5) {
        cout << "Enter a second number: ";
        cin >> valueTwo;
        cout << endl;
    }

    // Determine action based off menu selection.
    switch(menuSelection) 
    {
        case 1: 
            results = addition(valueOne, valueTwo);
            break;
        case 2: 
            results = subtraction(valueOne, valueTwo);
            break;
        case 3:
            results = multiply(valueOne, valueTwo);
            break;
        case 4:
            results = divide(valueOne, valueTwo);
            break;
        case 5:
            results = absoulte(valueOne);
            break;
        default:
            cout << "This action doesn't exist" << endl;
            break;
    }

    // Display the results to the user.
    displayResultsToUser(menuSelection, results, valueOne, valueTwo);

    // Ask and perform run again logic.
    bool shouldRunAgain = askToRunAgain();
    if (shouldRunAgain) {
        main();
    }
}