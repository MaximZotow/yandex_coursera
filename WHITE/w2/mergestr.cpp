#include <string>
#include <vector>
#include <iostream>
//include <algorithm>
using namespace std;;

void MoveStrings (vector<string>& source, vector<string>& destination)
{
	for (auto i : source)
		destination.push_back(i);
	source.clear();
}
void print (vector<string>& source)
{
	for (auto i : source)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector <string> a = {"1", "2", "3"};
	vector <string> b = {"a", "b", "c"};
	print(a);
	print(b);
	MoveStrings (a,b);
	print(a);
	print(b);
	return 0;
}
