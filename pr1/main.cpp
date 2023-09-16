#include <iostream>
#include <vector>
#include <fstream>

#include "cars.h"
#include "date.h"
using namespace std;

void loadData(vector<Car>& cars, istream& in) {
    while (!in.eof()) {
        Car c;
        c.load(in);
        cars.push_back(c);
    }
}

void printData(vector<Car>& cars) {
    for (auto& c : cars) {
        c.print();
    }
}

int main()
{
    vector <Car> cars;
    ifstream in("ist.txt");
    loadData(cars, in);

    printData(cars);
    return 0;
}
