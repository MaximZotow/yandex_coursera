#include <cmath>
#include <iostream>
#include <string>
using namespace std;;

int main()
{
	string input;
	cin >> input;
	int sum = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 'f')
			sum ++;
		if (sum == 2)
		{
			cout << i;
			break;
		}
	}
	if (sum == 0)
		cout << -2;
	else if (sum == 1)
		cout << -1;
	return 0;
}
