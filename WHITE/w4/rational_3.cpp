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

    Rational(long numerator, long denominator)
    {
        long del;
        long minus = -1;
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
	{
		Rational re(a.Numerator() - b.Numerator(), a.Denominator());
		return re;
	}

	else
	{
		long ch, zn;
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
		long ch, zn;
		ch = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
		zn = a.Denominator() * b.Denominator();
		Rational re(ch,zn);
		return re;
	}
}

Rational operator*(const Rational& a, const Rational& b)
{
	long ch, zn;
	ch = a.Numerator() * b.Numerator();
	zn = a.Denominator() * b.Denominator();
	Rational re(ch,zn);
	return re;
}

Rational operator/(const Rational& a, const Rational& b)
{
	Rational b1(b.Denominator(), b.Numerator());
	//Rational re = ch * zn
	return a * b1;
}


int main() {
	 {
	        Rational a(2, 3);
	        Rational b(4, 3);
	        Rational c = a * b;
	        bool equal = c == Rational(8, 9);
	        if (!equal) {
	            cout << "2/3 * 4/3 != 8/9" << endl;
	            return 1;
	        }
	    }

	    {
	        Rational a(5, 4);
	        Rational b(15, 8);
	        Rational c = a / b;
	        bool equal = c == Rational(2, 3);
	        if (!equal) {
	            cout << "5/4 / 15/8 != 2/3" << endl;
	            return 2;
	        }
	    }

	    cout << "OK" << endl;
	    return 0;
}
