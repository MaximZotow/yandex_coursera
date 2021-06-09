#include <string>
#include <vector>
#include <iostream>
//include <algorithm>
using namespace std;;

void Reverse(vector<int>& v)
{
	vector <int> tmp;
	for (int i = v.size(); i > 0; i--)
	{
		tmp.push_back(v[i - 1]);
		//cout << i << " " << v[i - 1] << endl;
	}
	v = tmp;

}

void print (vector<int>& source)
{
	for (auto i : source)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector <int> a = {1, 2, 3};
	//vector <string> b = {"a", "b", "c"};
	print(a);
	Reverse(a);
	print(a);
	return 0;
}
