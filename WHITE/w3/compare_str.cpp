#include <vector>
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;

string tl (const string& income)
{
	string outcome = income;
	for (int i = 0; i < income.size(); i++)
		outcome[i] = tolower(income[i]);
	return outcome;
}

int main() {
	vector<string> sorted;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string str;
		cin >> str;
		sorted.push_back(str);
	}
	cout << endl << endl;;
	sort(sorted.begin(), sorted.end(), [] (string& a, string& b) -> bool
		{

			return (tl(a) < tl(b));
		});
	for (const auto& i : sorted)
		cout << (i) << " ";
	/*string str1;
	cin >> str1;
	str1[0] = tolower(str1[0]);
	cout << str1;*/
}
