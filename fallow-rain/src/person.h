/*
 * person.h
 *
 *  Created on: Jan 14, 2024
 *      Author: samat
 */

#include <string>


using namespace std;

#ifndef PERSON_H_
#define PERSON_H_

class Person {
private:
	string firstName;
	string lastName;
	string streetAddress;
	string city;
	string zipCode;

public:
	Person(string fn, string ln, string add, string city, string zip);
	void displayData();
};





#endif /* PERSON_H_ */
