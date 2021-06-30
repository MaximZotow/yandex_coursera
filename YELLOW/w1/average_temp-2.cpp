#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
using namespace std;


int main() {
	int N, temp;
	vector<int> t;
	cin >> N;
	int64_t sum = 0;
	for (size_t i=0;i<N;i++)
	{
		cin >> temp;
		t.push_back(temp);
		sum+=temp;
	}
	double average = sum / static_cast<double>(N);
	vector<int> res;
	int i = 0;
	int sumt = 0;
	for (auto temps:t)
	{
		if (temps>average)
		{
			res.push_back(i);
			sumt++;
		}
		i++;
	}
	cout << sumt << endl;
	for (auto r:res)
		cout << r << " ";
    return 0;
}
