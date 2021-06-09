#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include<istream>
#include<ostream>
using namespace std;

class Rational
{
public:
    Rational()
    {
        // Реализуйте конструктор по умолчанию
        chisl = 0;
        znam = 1;
    }

    Rational(long numerator, long denominator)
    {
        long del;
        del = __gcd(numerator, denominator);
        if (numerator * denominator < 0)
        {
            chisl = -1 * abs(numerator / del);
            znam = abs(denominator / del);
        }
        else if (numerator * denominator >= 0 &&
                (numerator >= 0 || denominator >= 0))
        {
            chisl = abs (numerator / del);
            znam = abs(denominator / del);
        }
        else if (numerator * denominator >= 0 &&
                (numerator <= 0 && denominator <= 0))
        {
            chisl = abs (numerator / del);
            znam = abs(denominator / del);
        }
        else if (numerator == 0)
        {
            chisl = 0;
            znam = 1;
        }

    }

    long Numerator() const
    {
        // Реализуйте этот метод
        return chisl;
    }

    long Denominator() const
    {
        // Реализуйте этот метод
        return znam;
    }

private:
    // Добавьте поля
    long chisl;
    long znam;
};

bool operator==(const Rational& a, const Rational& b)
{
    if (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator())
        return true;
    return false;
}

// Реализуйте для класса Rational операторы ==, + и -
Rational operator-(const Rational& a, const Rational& b)
{
    Rational re;
    if (a.Denominator() == b.Denominator())
        return {a.Numerator() - b.Numerator(), a.Denominator()};
    else
    {
        long ch, zn;
        ch = a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator();
        zn = a.Denominator() * b.Denominator();
        return {ch, zn};
    }
}

Rational operator+(const Rational& a, const Rational& b)
{
    Rational re;
    if (a.Denominator() == b.Denominator())
        return {a.Numerator() + b.Numerator(), a.Denominator()};

    else
    {
        long ch, zn;
        ch = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
        zn = a.Denominator() * b.Denominator();
        return {ch, zn};
    }
}

Rational operator*(const Rational& a, const Rational& b)
{
    long ch, zn;
    ch = a.Numerator() * b.Numerator();
    zn = a.Denominator() * b.Denominator();
    return {ch, zn};
}

Rational operator/(const Rational& a, const Rational& b)
{
    Rational b1(b.Denominator(), b.Numerator());
    //Rational re = ch * zn
    return a * b1;
}

istream& operator >> (istream& stream, Rational& drob) {
    int a, b;
    char c;
    stream >> a >> c >> b;
    if (stream && c == '/') {
        drob = Rational(a, b);
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& drob)
{
    stream << drob.Numerator() << "/" << drob.Denominator();
    return stream;
}

int main() {
     {
            ostringstream output;
            output << Rational(-6, 8);
            if (output.str() != "-3/4") {
                cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                return 1;
            }
        }

        {
            istringstream input("5/7");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal) {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 2;
            }
        }

        {
            istringstream input("");
            Rational r;
            bool correct = !(input >> r);
            if (!correct) {
                cout << "Read from empty stream works incorrectly" << endl;
                return 3;
            }
        }

        {
            istringstream input("5/7 10/8");
            Rational r1, r2;
            input >> r1 >> r2;
            bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                return 4;
            }

            input >> r1;
            input >> r2;
            correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                return 5;
            }
        }

        {
            istringstream input1("1*2"), input2("1/"), input3("/4");
            Rational r1, r2, r3;
            input1 >> r1;
            input2 >> r2;
            input3 >> r3;
            bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
            if (!correct) {
                cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                     << r1 << " " << r2 << " " << r3 << endl;

                return 6;
            }
        }

        cout << "OK" << endl;
        return 0;
//    istringstream input ("5*");
//    Rational r1;
//    input >> r1;
//    cout << r1;
}
