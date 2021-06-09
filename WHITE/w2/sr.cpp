#include <string>
#include <vector>
#include <iostream>
//include <algorithm>
using namespace std;;

void PrintVector(const vector<string>& v) {
  for (string s : v) {
    cout << s << endl;
  }
}

int main() {
	int n;
	int m = 0;
	double sr = 0;
	cin >> n;
	vector <int > temp(n);
	//int sr;
	for (auto& i : temp)
	{
		cin >> i;
		sr += i;
	}
	sr /= n;
	//cout << "sr  = " << sr<< endl;
	for (auto& i : temp)
		if (i > sr)
			m += 1;
	cout << m << endl;
	for (int i = 0; i < n; i++)
		if (temp[i] > sr)
			cout << i << " ";
  return 0;
}

