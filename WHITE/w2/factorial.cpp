#include <iostream>
using namespace std;;

int Factorial (int N)
{
	int sum = 1;
	if (N <= 0)
		return sum;
	else
		for (int i = N; i > 0; i--)
			sum *= i;
	return sum;
}
int main()
{
	int n;
	cin >> n;
	cout << Factorial(n);
	return 0;
}
