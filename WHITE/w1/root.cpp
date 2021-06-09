#include <cmath>
#include <iostream>
#include <string>
using namespace std;;

int main()
{
	double a,b,c;
	cin >> a >> b >> c;
	if (a != 0)
	{
		double d = (b * b - 4 * a * c);
		if (d > 0)
			cout << (-b + sqrt(d)) / (2 * a) << " " << (-b - sqrt(d)) / (2 * a) << endl;
		else if (d == 0)
			cout << -b / (2 * a) << endl;
		else
			cout << " ";
	}
	else if (a == 0 && b == 0 && c != 0)
		cout << " ";
	else
		cout << 1.0 * (-c) / b << endl;
	return 0;
}
