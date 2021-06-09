#include <iostream>
#include <algorithm>
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

    Rational(int numerator, int denominator)
    {
        int del;
        int minus = -1;
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

    int Numerator() const
    {
        // Реализуйте этот метод
    	return chisl;
    }

    int Denominator() const
    {
        // Реализуйте этот метод
    	return znam;
    }

private:
    // Добавьте поля
    int chisl;
    int znam;
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
	{
		Rational re(a.Numerator() - b.Numerator(), a.Denominator());
		return re;
	}

	else
	{
		int ch, zn;
		ch = a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator();
		zn = a.Denominator() * b.Denominator();
		Rational re(ch,zn);
		return re;
	}
}

Rational operator+(const Rational& a, const Rational& b)
{
	Rational re;
	if (a.Denominator() == b.Denominator())
	{
		Rational re(a.Numerator() + b.Numerator(), a.Denominator());
		return re;
	}

	else
	{
		int ch, zn;
		ch = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
		zn = a.Denominator() * b.Denominator();
		Rational re(ch,zn);
		return re;
	}
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
