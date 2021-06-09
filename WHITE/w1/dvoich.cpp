#include <vector>
#include <iostream>
using namespace std;;

int main()
{
	int n, i, size;
	vector<int> dva;
	cin >> n;
	do
	{
		dva.push_back(n % 2);
		n /= 2;
	} while (n > 0);
	size = dva.size();
	for (i = size; i > 0; --i)
		cout << dva[i - 1];
	return 0;
}
