//#include <string>
//#include <vector>
#include <iostream>
//include <algorithm>
using namespace std;;

void UpdateIfGreater (int first, int& second)
{
	if (first > second)
		second = first;
}

int main()
{
	int a,b;
	cin >> a >> b;
	//cout << a << " " << b << endl;
	UpdateIfGreater(5,b);
	cout << a << " " << b << endl;
	return 0;
}
