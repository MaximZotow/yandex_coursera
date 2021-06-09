#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;;

void PrintVector(const vector<string>& v) {
  for (string s : v) {
    cout << " " << s;
  }
  cout << endl;
}

void PrintDict (const map <char, int>& m)
{
	for (auto& i : m)
		cout << i.first << " " << i.second << endl;
}

void BuildCharCounters (const string& a, const string& b)
{
	map <char, int> ma;
	map <char, int> mb;
	for (char i : a)
		++ma[i];
	for (char i : b)
		++mb[i];
	if (ma == mb) cout << "YES\n";
	else cout << "NO\n";
}

/*
int count (const string& str)
{
	int count = 0;
	for (auto i : str)
		if (i == ' ')
			++count;
	return count;
	//else return count - 1;
} */

int main()
{
	int n;
	string a,b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		BuildCharCounters(a, b);
	}
	return 0;
}
