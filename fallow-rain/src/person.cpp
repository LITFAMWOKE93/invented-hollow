/*
 * person.cpp
 *
 *  Created on: Jan 14, 2024
 *      Author: samat
 */
#include <iostream>
#include <string>
#include "person.h"
using namespace std;


Person::Person(string fn, string ln, string add, string city, string zip) {
    this->firstName = fn;
    this->lastName = ln;
    this->streetAddress = add;
    this->city = city;
    this->zipCode = zip;
}

void Person::displayData() {
    cout << "PERSONAL INFORMATION\n";
    cout << "First Name: " + this->firstName + "\n" ;
    cout << "Last Name: " + this->lastName + "\n" ;
    cout << "Street Address: " + this->streetAddress + "\n" ;
    cout << "City: " + this->city + "\n" ;
    cout << "Zip Code: " + this->zipCode + "\n" ;
}
