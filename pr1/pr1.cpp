#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct cars {
    string numberOfCar;
    int dd, mm, yyyy;
    void load_txt(istream& ist);
    void print_txt();
};

void cars::load_txt(istream& ist)
{
    ist >> numberOfCar;
    ist >> dd;
    ist >> mm;
    ist >> yyyy;
}

void cars::print_txt()
{
    cout << numberOfCar << " ";
    cout << yyyy << "." << mm << "." << dd << "\n";
}

void load_txt(vector<cars>& data, istream& ist)
{
    while (!ist.eof())
    {
        cars d;
        d.load_txt(ist);
        data.push_back(d);
    }
}

void print_data(vector<cars>& data)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i].print_txt();
        cout << endl;
    }
}

int main()
{
    vector <cars> data;
    ifstream in("ist.txt");
    load_txt(data, in);
    print_data(data);
    return 0;
}
