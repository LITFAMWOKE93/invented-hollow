//============================================================================
// Name        : fallow-rain.cpp
// Author      : Sam T
// Version     :
// Copyright   : None
// Description : Mod 5 Critical Thinking CSC450
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, char **argv) {

	// Create two different streams for I/O operations
	ofstream outfile;
	ofstream reverseFile;


	outfile.open("CSC450_CT5_mod5.txt", ios_base::app);

	if (outfile.fail()) {
		cout << "File failed to open." << endl;
		return 1;
	}

	outfile << "Here is some new text to be appended";
	// Need to close any stream so that they don't interfere with new ones
	outfile.close();

	// Now we treat the same file as an input file for reading
	ifstream infile("CSC450_CT5_mod5.txt");

	// Another file check
	if (!infile) {
		cout << "File not found for reading." << endl;
		return 1;
	}

	// A string stream object for placing all contents of file into a string, only works on input files.
	stringstream buffer;

	buffer << infile.rdbuf();

	// Stream can be closed once contents are read.
	infile.close();

	// Create a string to store buffer contents from file.
	string file_contents;

	file_contents = buffer.str();

	reverseFile.open("CSC450-mod5-reverse.txt");

	if (reverseFile.fail()) {
		cout << "File failed to open." << endl;
		return 1;
	}

	reverse(file_contents.begin(), file_contents.end());
	// Built in string reverse method from the algorithm header

	reverseFile << file_contents << endl;

	// Always close streams
	reverseFile.close();








	return 0;
}


