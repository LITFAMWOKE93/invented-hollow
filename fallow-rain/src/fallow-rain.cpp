//============================================================================
// Name        : fallow-rain.cpp
// Author      : Sam T
// Version     :
// Copyright   : None
// Description : Mod 1 Critical Thinking CSC450
//============================================================================

#include <iostream>
#include <string>
#include <limits>
using namespace std;
string getString() {
	// Dynamically allocated array chars
	// string objects do not require null terminators
	string s1;
	string s2;
	cout << "Please enter in your first string." << endl;
	// the getline() method includes spaces and consumes the newline char
	getline(cin, s1);
	cout << "Please enter in your second string." << endl;
	getline(cin, s2);



	return s1 + s2;

}


int main(int argc, char **argv) {

	// Iterating loop to run the program three times.
	for (int i = 0; i < 3; i++) {
		// Clear the buffer before reading a new string to make sure nothing lingers for the next call.
		if (i != 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << getString() << endl;
	}

	return 0;
}
