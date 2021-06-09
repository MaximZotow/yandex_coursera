#include <string>
#include <iostream>
using namespace std;;

bool IsPalindrom(string input)
{
	int len = input.length();
	for (int i = 0; i < len / 2; i++)
	{
		//cout << len / 2 << " ";
		//cout << input[i] << " ";
		//cout << input[(len - i - 1)]<< " ";
		if ((input[i]) != (input[(len - i - 1)]))
			return false;
			//cout << "false";
	}
	return true;
}
int main()
{
	string input;
	cin >> input;
	cout << IsPalindrom(input);
	return 0;
}
