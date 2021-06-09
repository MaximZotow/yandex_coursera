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

void thing(vector <bool>& lane,
		string& name, int& code)
{
	int count = 0;
	if (name == "WORRY")
		lane[code] = true;
	else if (name == "QUIET")
		lane [code] = false;
	else if (name == "COME")
	{
		if (code > 0)
			for (int i = 0; i < code; i++)
				lane.push_back(false);
		else if (code < 0)
			lane.resize(lane.size() + code);
	}
	else if (name == "WORRY_COUNT")
	{
		for (auto i : lane)
			if (i == true)
				++count;
		cout << count << endl;
	}
}

int main() {
	vector <bool> lane;
	string op_name;
	int code, Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> op_name;
		if (op_name != "WORRY_COUNT")
			cin >> code;
		//cout << op_name << code;
		thing(lane, op_name, code);
	}
  return 0;
}

