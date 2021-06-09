#include <vector>
#include <iostream>
#include <string>
#include <set>

#include <algorithm>
using namespace std;;

int main()
{
	int q;
	set <string> s;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	cout << s.size();
}











