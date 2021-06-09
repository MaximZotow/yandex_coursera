#include <iostream>
#include<string>
#include<sstream>
#include<istream>
#include<ostream>
using namespace std;

//struct test
//{
// int a;
// int b;
//};

class Rational
{
public:
 Rational()
 {
 chisl = 0;
 znam = 1;
 }
 Rational(const int& a, const int& b)
 {
 chisl = a;
 znam = b;
 //return {a,b};
 }
 int Numerator() const
 {
 return chisl;
 }
 int Denominator () const
 {
 return znam;
 }
private:
 int chisl, znam;
};

Rational operator+(const Rational& a, const Rational& b)
{
 return {a.Numerator() + b.Numerator(),
 a.Denominator() + b.Denominator()};
}

Rational operator-(const Rational& a, const Rational& b)
{
 return {a.Numerator() - b.Numerator(),
 a.Denominator() - b.Denominator()};
}

bool operator==(const Rational& a, const Rational& b)
{
 if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()))
 return (true);
 else return(false);
}

ostream& operator«(ostream& stream, const Rational& a)
{
 stream « a.Numerator() « "/" « a.Denominator();
 return stream;
}

istream& operator»(istream& stream, Rational& rat)
{
 int a, b;
 string check;
 getline(stream,check);
 if (check.size() != 0)
 {
 stream.seekg(0);
 stream » a;
 stream.ignore(1);
 stream » b;
 rat = {a,b};
 return stream;
 }
}
int main() {
 {
 ostringstream output;
 output « Rational(-6, 8);
 if (output.str() != "-6/8") {
 cout « "Rational(-6, 8) should be written as \"-3/4\"" « endl;
 return 1;
 }
 }

 {
 istringstream input("5/7");
 ostringstream output;
 Rational r;
 input » r;
 //cout « Rational(2,5);
 bool equal = r == Rational(5, 7);
 if (!equal) {
 cout « "5/7 is incorrectly read as " « r « endl;
 return 2;
 }
 }

 {
 istringstream input("");
 Rational r;
 bool correct = !(input » r);
 if (!correct) {
 cout « "Read from empty stream works incorrectly" « endl;
 return 3;
 }
 }

 {
 istringstream input("5/7 10/8");
 Rational r1, r2;
 input » r1 » r2;
 bool correct = r1 == Rational(5, 7) && r2 == Rational(10, 8);
 if (!correct) {
 cout « "Multiple values are read incorrectly: " « r1 « " " « r2 « endl;
 return 4;
 }

 input » r1;
 input » r2;
 correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
 if (!correct) {
 cout « "Read from empty stream shouldn't change arguments: " « r1 « " " « r2 « endl;
 return 5;
 }
 }

 {
 istringstream input1("1*2"), input2("1/"), input3("/4");
 Rational r1, r2, r3;
 input1 » r1;
 input2 » r2;
 input3 » r3;
 bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
 if (!correct) {
 cout « "Reading of incorrectly formatted rationals shouldn't change arguments: "
 « r1 « " " « r2 « " " « r3 « endl;

 return 6;
 }
 }

 cout « "OK" « endl;
 return 0;
}
