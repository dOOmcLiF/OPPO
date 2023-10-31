#pragma once
#include <string>
#include "date.h"

using namespace std;

class Car {

public:
	string numberOfCar;
	Date date;

	Car();
	Car(const string& num, Date d);

	void load(istream& in);
	void print() const;
	void validateNumber(string numberOfCar);
};
