#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include<istream>
#include<ostream>
#include<map>
#include<set>
#include<vector>
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

bool operator>(const Rational& a,const Rational& b)
{
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator<(const Rational& a, const Rational& b)
{
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
