#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set <string>s;
	for (auto& val : m)
		s.insert(val.second);
	return(s);
}

int main()
{
	map<string, set<string>> synonims;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string action;
		cin >> action;
		if (action == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			synonims[word1].insert(word2);
			synonims[word2].insert(word1);
		}
		if (action == "COUNT")
		{
			int counter = 0;
			string word;
			cin >> word;
			cout << synonims[word].size() << endl;
		}
		if (action == "CHECK")
		{
			string word1, word2;
			int counter = 0;
			cin >> word1 >> word2;
			if (synonims[word1].count(word2) != 0 || synonims[word2].count(word1) != 0)
				cout << "YES\n";
			else cout << "NO\n";

		}
	}
}











