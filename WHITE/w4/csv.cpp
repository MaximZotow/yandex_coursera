#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    int str, stlb;
    string line;
    input >> str >> stlb;
    input.ignore(1);
    for (int i = 0; i <str; i++)
    {
    	for (int j = 1; j < stlb; j++)
    	{
    	getline(input, line, ',');
    	cout << setw(10) << line << " ";
    	}
    	getline(input, line);
    	cout << setw(10) << line << endl;
    }

}


