#include <vector>
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
	  stroka.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(stroka.begin(), stroka.end());
    return stroka;
  }
private:
  vector<string> stroka;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}







