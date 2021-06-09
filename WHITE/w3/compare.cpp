#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	vector<int> sorted;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int num;
		cin >> num;
		sorted.push_back(num);
	}
	sort(sorted.begin(), sorted.end(), [] (int a, int b) -> bool
		{

			return (abs(a) < abs(b));
		});
	for (const auto& i : sorted)
		cout << (i) << " ";
}
