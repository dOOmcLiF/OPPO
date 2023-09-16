#include "cars.h"
#include <string>
#include <iostream>

using namespace std;

Car::Car() {
	numberOfCar = "";
	date = Date();
}


Car::Car(string num, Date d) : numberOfCar(num), date(d) {}

void Car::load(istream& in) {
	in >> numberOfCar;

	int d, m, y;
	in >> d >> m >> y;

	date.day = d;
	date.month = m;
	date.year = y;
}

void Car::print() const {
	cout << numberOfCar << " ";
	cout << date.year << "." << date.month << "." << date.day << "\n";
}