#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>
#include <windows.h>

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
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector <Car> cars;
    ifstream in("ist.txt");
    try {
        loadData(cars, in);
        printData(cars);
    }
    catch (runtime_error& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    }
    catch (out_of_range& e) {
        cerr << "Variable is out of range: " << e.what() << endl;
    }
    return 0;
}
