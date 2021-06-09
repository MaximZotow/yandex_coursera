#include <vector>
#include <iostream>
#include <string>
using namespace std;;

void PrintVector(const vector<string>& v) {
  for (string s : v) {
    cout << " " << s;
  }
  cout << endl;
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
	vector <int> days_in_month = {31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31};
	vector <vector<string>> current_month (days_in_month[0]);
	int q;
	cin >> q;
	/*int test = 0;
	for (int i = 0; i < 15; i++)
	{
		test = (i) % 12;
		cout << "i = "<< i << "test = " << test << endl;
	} */
	string action;
	string todo;
	int day;
	int next = 0;
	for (int i = 0; i < q; ++i)
	{
		cin >> action;
		if (action == "ADD")
		{
			cin >> day >> todo;
			current_month[day - 1].push_back(todo);
		}
		if (action == "DUMP")
		{
			cin >> day;
			cout << current_month[day - 1].size();;
			PrintVector(current_month[day - 1]);
		}
		if (action == "NEXT")
		{

			if (days_in_month[next] > days_in_month[(next + 1) % 12])
			{
				for (int k = days_in_month[(next + 1) % 12];
						k < days_in_month[next]; ++k)
				{

					//current_month[days_in_month[(next + 1) % 12] - 1].push_back("");
					current_month[days_in_month[(next + 1) % 12] - 1].insert(
							end(current_month[days_in_month[(next + 1) % 12] - 1]),
							begin(current_month[k]), end(current_month[k]));
					current_month[k].clear();
				}
			}
			next = (next + 1) % 12;
			current_month.resize(days_in_month[next]);
			//cout << endl<< "next = " << next;
		}
	}
	//cin >> next;
	//cout << (next + 1) % 12;
}
