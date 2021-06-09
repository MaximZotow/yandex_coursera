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

void PrintDict (const map <string, string>& m)
{
	for (auto& i : m)
		if (i.second == "" || i.first == "") continue;
		else cout << i.first << "/" << i.second << " ";
}

void BuildCharCounters (const string& a, const string& b)
{
	map <char, int> ma;
	map <char, int> mb;
	for (char i : a)
		++ma[i];
	for (char i : b)
		++mb[i];
	if (ma == mb) cout << "YES";
	else cout << "NO";
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
	int q;
	string action, new_capital, country, new_country;
	cin >> q;
	map <string, string> countries;
	//cout << countries.("msc");
	for (int i = 0; i < q; i++)
	{
		cin >> action;
		if (action == "CHANGE_CAPITAL")
		{
			cin >> country >> new_capital;
			if (countries.count(country) == 0)
			{
				countries[country] = new_capital;
				cout << "Introduce new country " << country << " with capital "
						<< countries[country] << endl;
			}
			else if (countries[country] == new_capital)
				cout << "Country " << country <<
				" hasn't changed its capital " << endl;
			else if (countries[country] != new_capital)
			{
				cout << "Country " << country <<" has changed its capital from " <<
						countries[country] << " to " << new_capital << endl;
				countries[country] = new_capital;
			}

		}
		else if (action == "RENAME")
		{
			cin >> country >> new_country;

			/*if ((country != new_country) && (countries[country] == "")
								&& (countries[new_country] != ""))
			{
				cout << "Country " << country << " with capital " <<
						countries[country] << " has been renamed to " <<
						new_country << endl;
				countries[new_country] = countries[country];
				countries.erase(country);
			}
			else cout << "Incorrect rename, skip" << endl;
			//cout << "razmer " << countries.size(); */
			if (country == new_country || countries.count(country) == 0 || countries.count(new_country) != 0 )
				cout << "Incorrect rename, skip" << endl;
			else
			{
				cout << "Country " << country << " with capital " <<
										countries[country] << " has been renamed to " <<
										new_country << endl;
								countries[new_country] = countries[country];
								countries.erase(country);
			}
		}
		else if (action == "ABOUT")
		{
			cin >> country;
			if (countries.count(country) == 0)
				cout << "Country " << country << " doesn't exist" << endl;
			else
				cout << "Country " << country << " has capital " << countries[country] << endl;
		}
		//PrintDict(countries);
		else if (action == "DUMP")
		{
			//cout << "razmer " << countries.size();
			//PrintDict(countries);
			if (countries.size() == 0) cout << "There are no countries in the world" << endl;
			else PrintDict(countries);
		}
	}
	return 0;
}
