// SieveOfEratosthenes.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"

//Sieve of Eratosthenes prime number finder
//by Shane
//
//The code requires an input integer less than the arrSize variable
//and will then return all primes less than that input using the sieve of Eratosthenes
//
//Feel free to look at this code and learn but please don't reuse it without my permission
//
//This code works best using a proper C compiler rather than the SoloLearn testing environment
//due to needing input from the user
//
//
//original code: 4th March 2017
//update: 6th March 2017 - timing routine and increased upper bound
//update: 7th March 2017 - first error trapping routine
//update: 12th March 2017 - additional comments
//update: 19th March 2017 - additional error trapping, no longer including 1 as prime
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>
using namespace std;

int main()
{
	//declare the variables
	const int arrSize = 150001;   //this is included as a constant so that the upper bound can be changed easily
								  //but note that higher values won't display all primes on screen and won't sum into a "long"
	int maxValue = 0;
	string inputStr = "";
	bool testArray[arrSize];
	int i = 0, j = 0;
	int primeCount = 0;
	long primeTotal = 0;
	bool loopContinue = true;
	bool validInput = false;
	string loopAnswer = "";
	clock_t startTime, currentTime;
	double elapsedSeconds;


	while (loopContinue == true) {
		//initialise the array
		for (i = 0; i < arrSize; i++) {
			testArray[i] = true;
		}

		//get input from the user
		validInput = false;
		while (validInput == false) {
			cout << "Please enter a number from 2 to " << arrSize - 1 << " > ";
			getline(cin, inputStr);

			//try converting to integer 
			stringstream myStream(inputStr);
			if (myStream >> maxValue) {
				if (maxValue > 1 && maxValue < arrSize) {
					validInput = true;
				}
				else {
					cout << "That value isn't valid, please try again" << endl << endl;
				}
			}
			else {
				cout << "That value isn't valid, please try again" << endl << endl;
			}
		}

		startTime = clock();

		//Use the sieve of Eratosthenes to remove all non-primes
		for (i = 2; i < sqrt(maxValue); i++) {
			if (testArray[i] == true) {
				for (j = 2; j <= maxValue / i; j++) {
					testArray[i * j] = false;
				}
			}
		}

		//output all primes as well as a total and a count
		cout << "The primes less than " << maxValue << " are: " << endl;
		primeCount = 0;
		primeTotal = 0;
		for (i = 2; i < maxValue; i++) {
			if (testArray[i] == true) {
				cout << i << " ";
				primeCount++;
				primeTotal += i;
			}
		}
		cout << endl << "The number of primes is: " << primeCount << " and the sum is: " << primeTotal << endl;

		currentTime = clock();
		elapsedSeconds = ((currentTime -  startTime) / (CLOCKS_PER_SEC / 1.0));
		cout.precision(4);
		cout << "This took: " << fixed << elapsedSeconds << " seconds to run" << endl << endl;

		cout << "Do you want another go (Y/N)? ";
		getline(cin, loopAnswer);
		if (loopAnswer == "y" || loopAnswer == "Y") {
			loopContinue = true;
			cout << endl;
		}
		else {
			loopContinue = false;
		}

	}

    return 0;
}

