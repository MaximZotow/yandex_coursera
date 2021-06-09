#include <vector>
#include <string>
#include <iostream>
using namespace std;;

int main()
{
	vector<string> stroka = {"", "", ""};
	cin >> stroka[0] >> stroka[1] >> stroka[2];
	if (stroka [0] <= stroka [1] && stroka [0] <= stroka [2])
		cout << stroka [0];
	else if (stroka [1] <= stroka [0] && stroka [1] <= stroka [2])
		cout << stroka [1];
	else if (stroka [2] <= stroka [0] && stroka [2] <= stroka [1])
		cout << stroka [2];
}
