#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Specialization
{

	explicit Specialization(string nm) {name = nm;};
	string name;
};

struct Course
{
	explicit Course(string nm) {name = nm;};
	string name;
};

struct Week
{
	explicit Week(string nm) {name = nm;};
	string name;
};

struct LectureTitle
{
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization spec,
			Course cour, Week wk)
	{
		specialization = spec.name;
		course = cour.name;
		week = wk.name;
	}

};
int main()
{
	return 0;
}

