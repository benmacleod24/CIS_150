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

int passingByValue(int x) {
    cout << "x in Func1: " << x << endl;
    x += 3;
    cout << "x in Func2: " << x << endl;
    return x;
}

// Entry Point
int main()
{
    int x = 10;
    cout << "x before call: " << x << endl;
    x = passingByValue(x);
    cout << "x after call: " << x << endl;
}