#include <string>
#include <iostream>
#include <vector>
#include <locale>
#include <map>
#include <algorithm>

using namespace std;


struct ns
{
	string name;
	string surname;
};

class ReversibleString
{
public:
	ReversibleString(){};
	ReversibleString(const string& str)
	{
		s = str;
	}
	void Reverse ()
	{
		reverse (s.begin(), s.end());
	}
	string ToString () const
	{
		return s;
	}
private:
	string s;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}






