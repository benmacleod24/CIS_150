#include <iostream>
#include <iomanip> 
#include <math.h>

using namespace std;

/*
 * Check Primality of a number.
 * @param number Number to check that is prime.
 */
bool checkPrimality(int number) {

	// If the number is one or zero, they are 
	// netiher prime nor not.
	if (number <= 1) return false;

	// If n is two we will return since we know
	// it will be true.
	if (number == 2) return true;

	// Loop from 2 to square root of n
	// checking if it is a prime number.
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) return false;
	}

	return true;
}

/*
 * Print the header to the console.
 * @param totalNumOfPrimes Total number of prime numbers.
 * @param maxCount Max size for the array.
 */
void printHeader(int totalNumOfPrimes, int maxCount) {
	const string divider = "================================================================================";

	// Print the header to the console.
	cout << setw(divider.length() / 1.5) << "P R I M E  N U M B E R S" << endl;
	cout << setw(divider.length() / 3.5) << "There are " << totalNumOfPrimes << " number of prime numbers between 1 and " << maxCount << endl;
	cout << divider << endl;
}

/*
 * Print results to the console.
 * @param primeNumbers List of prime numbers.
 * @param maxSize Max size of the array, for some reason sizeof
 *  wouldn't work.
 */
void printResults(int primeNumbers[], int maxSize) {
	int nextLine = 1;

	// Loop through array and print each number.
	// For some reason sizeof(primeNumbers) wasn't working
	// would like to know why?
	for (int i = 1; i < maxSize; i++) {

		// If the element exist in the array
		// print it to the console.
		if (primeNumbers[i]) {

			// Keep track of current line and 
			// when to make a new line.
			if (nextLine > 10) {
				cout << endl;
				nextLine = 1;
			}

			// Print the primt integer to the console.
			cout << setw(7) << primeNumbers[i] << ",";

			// Increment next line.
			nextLine++;
		}
	}
}


int main()
{
	const int MAX_COUNT = 10000;
	int totalNumOfPrimes = 0;
	int primeNumbers[MAX_COUNT] = {};

	// Loop through the max count and check if each number
	// is a prime number.
	for (int i = 1; i < MAX_COUNT; i++) {
		const bool isPrime = checkPrimality(i);
		if (isPrime) {
			primeNumbers[i] = i;
			totalNumOfPrimes++;
		}
	}

	// Print the results to the console.
	printHeader(totalNumOfPrimes, MAX_COUNT);
	printResults(primeNumbers, MAX_COUNT);

}
