#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct BDay
{
	int day;
	int month;
	int year;
};

struct student
{
	string name;
	string surname;
	BDay birth;
};

int main() {
	vector <student> students;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		student person;
		cin >> person.name >> person.surname >>
		person.birth.day >> person.birth.month >>
		person.birth.year;
		students.push_back(person);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string question;
		int stud_num;
		cin >> question >> stud_num;
		stud_num--;
		if (question == "name" && stud_num >=0
				&& stud_num < n)
		{

			cout << students[stud_num].name << " " <<
				students[stud_num].surname << endl;
		}
		else if (question ==  "date" && stud_num >=0
				&& stud_num < n)
		{
			cout << students[stud_num].birth.day << "." <<
					students[stud_num].birth.month << "." <<
					students[stud_num].birth.year << endl;
		}
		else cout << "bad request\n";
	}
	return 0;

}


