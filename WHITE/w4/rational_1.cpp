#include <iostream>
#include <numeric>
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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
