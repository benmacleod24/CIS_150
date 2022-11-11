#include <iostream>
#include <iomanip>

using namespace std;

void promptMethod(int optionIndex, string method)
{
    cout << to_string(optionIndex) << ".";
    cout << setw(method.length() + 2);
    cout << method << endl;
}

int main()
{

    bool hasError = false;
    int optionSelected = 0;
    int firstNumber = 0;
    int secondNumber = 0;

    // Prompt user with list options.
    cout << "What would you like to do?" << endl;
    promptMethod(1, "Add 2 Numbers");
    promptMethod(2, "Subtract 2 Numbers");
    promptMethod(3, "Multiply 2 Numbers");
    promptMethod(4, "Divide 2 Numbers");

    cout << "Please enter your selection: ";
    cin >> optionSelected;
    cout << endl;

    if (optionSelected < 1 || optionSelected > 4)
    {
        hasError = true;
        cout << "You broke my program. You needed to insert a number between 1 and 4." << endl;
    }

    if (!hasError)
    {
        cout << "Enter the first number: ";
        cin >> firstNumber;

        cout << "Enter the second number: ";
        cin >> secondNumber;
        cout << endl;

        if (optionSelected == 4 && (secondNumber == 0 || !secondNumber))
        {
            hasError = true;
            cout << "You broke my program. You can not divide a number by 0." << endl;
        }
    }

    
    if (!hasError)
    {
        cout << "You chose to perform the following operation." << endl;
        switch (optionSelected)
        {
            case 1:
                cout << firstNumber << " + " << secondNumber << " = " << (firstNumber + secondNumber) << endl;
                break;
            case 2:
                cout << firstNumber << " - " << secondNumber << " = " << (firstNumber - secondNumber) << endl;
                break;
            case 3:
                cout << firstNumber << " * " << secondNumber << " = " << (firstNumber * secondNumber) << endl;
                break;
            case 4:
                cout << firstNumber << " / " << secondNumber << " = " << (firstNumber / secondNumber) << endl;
                break;
            default:
                cout << "You did not pick a valid operation, please run again.";
                break;
        }
        cout << "Thanks for using the program" << endl;
    }

}