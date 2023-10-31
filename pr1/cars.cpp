#include "cars.h"
#include <cstring>
#include <iostream>
#include <exception>

using namespace std;

Car::Car() {
	numberOfCar = "";
	date = Date();
}


Car::Car(const string& num, Date d) : numberOfCar(num), date(d) {}

void Car::validateNumber(string value) {
	string alphabet = "ABEKMHOPCTYX";
	string figures = "0123456789";
	if ((alphabet.find(value[0]) == -1) || (alphabet.find(value[4]) == -1) || (alphabet.find(value[5]) == -1)) {
		throw runtime_error("Invalid alphabet format in numbers!");
	}
	if ((figures.find(value[1]) == -1) || (figures.find(value[2]) == -1) || (figures.find(value[3]) == -1)) {
		throw runtime_error("Invalid figures format in numbers!");
	}
}

void Car::load(istream& in) {
	in >> numberOfCar;
	if (in.fail())
		throw runtime_error("!!");
	validateNumber(numberOfCar);
	date.load(in);
}

void Car::print() const {
	cout << numberOfCar << " ";
	date.print(cout);
}