#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;;


bool IsPalindrom(string input)
{
	int len = input.length();
	for (int i = 0; i < len / 2; i++)
	{
		//cout << len / 2 << " ";
		//cout << input[i] << " ";
		//cout << input[(len - i - 1)]<< " ";
		if ((input[i]) != (input[(len - i - 1)]))
			return false;
			//cout << "false";
	}
	return true;
}


vector<string> PalindromFilter (vector<string> words, int minLength)
{
	vector<string> result;
	for (string word : words)
	{
		if (IsPalindrom(word) && word.size() >= minLength)
		{
			result.push_back(word);
		}
	}
	return result;
}

int main()
{
	//string test;
	int len = 2;
	vector<string> final;

	vector<string> test = {"aaa", "abc", "aba"};
	final = PalindromFilter(test, len);
	for (string i : final)
		cout << i << " ";
	//getline (cin, test);
	//cout << test;

	return 0;
}
