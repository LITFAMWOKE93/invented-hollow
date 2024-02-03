//============================================================================
// Name        : fallow-rain.cpp
// Author      : Sam T
// Version     :
// Copyright   : None
// Description : Mod 3 Critical Thinking CSC450
//============================================================================

#include <iostream>
#include <limits>

using namespace std;


int main(int argc, char **argv) {

	// Declare variables

		int num1;
		int num2;
		int num3;



	try {
		// Get input from the user
		cout << "Please enter in a three numbers" << endl;

		if (!(cin >> num1 >> num2 >> num3)) {
			//clear the buffer
			cin.clear();
			//ingore the line from any more retreival
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw runtime_error("Invalud input, Integers only");
		}


		int *ptr1 = new int(num1);
		int *ptr2 = new int(num2);
		int *ptr3 = new int(num3);

		cout << "The values enter are, " << num1 << "," << num2 << "," << num3 << endl;
		cout << "The values are dynamically allocated and are stored as: " << *ptr1 << "," << *ptr2 << "," << *ptr3 << endl;
		cout << "at the memory locations " << &ptr1 << "," << &ptr2 << "," << &ptr3 << endl;



		delete ptr1;
		delete ptr2;
		delete ptr3;

		cout << "Memory has been erased" << endl;
	} catch (const bad_alloc& e) {
		cerr << "Bad Allocation: " << e.what() << endl;
		return 1;
	} catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}
