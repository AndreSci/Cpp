#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>



using namespace std;

int NOD(const int& numerator, const int& denominator)
{
	int a, b;
	a = numerator;
	b = denominator;

	while (a > 0 && b > 0)
	{
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

class Rational {
public:
	Rational()
	{
		p = 0;
		q = 1;
	}

	Rational(const int& numerator, const int& denominator) {

		if (numerator == 0) {
			p = 0;
			q = 1;
		}
		else if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
			int x = abs(numerator);
			int y = abs(denominator);
			int NODres = NOD(x, y);

			p = -numerator / NODres;
			q = -denominator / NODres;
		}
		else {
			int x = abs(numerator);
			int y = abs(denominator);
			int NODres = NOD(x, y);

			p = numerator / NODres;
			q = denominator / NODres;
		}
	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}
private:
	int p = 0;		// целое
	int q = 1;		// натуральное не может быть 0 или меньше?????

};

Rational operator+(const Rational& a, const Rational& b)	// a/b + c/d = (a*d + b* c)/(b*d)
{
	Rational Plus(a.Numerator()*b.Denominator() + a.Denominator()*b.Numerator(), a.Denominator()*b.Denominator());
	return Plus;
}

Rational operator-(const Rational& a, const Rational& b)
{
	Rational Minus(a.Numerator()*b.Denominator() - a.Denominator()*b.Numerator(), a.Denominator()*b.Denominator());
	return Minus;
}

bool operator==(const Rational& a, const Rational& b)
{
	if(a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator())
		return true;
	else
		return false;
}

Rational operator*(const Rational& a, const Rational& b)
{
	Rational mult(a.Numerator()*b.Numerator(), a.Denominator()*b.Denominator());
	return mult;
}
Rational operator/(const Rational& a, const Rational& b)
{
	Rational div(a.Numerator()*b.Denominator(), a.Denominator()*b.Numerator());
	return div;
}

ostream& operator<<(ostream& out, const Rational& a)
{
	out << setfill('0');
	out << a.Numerator() << "/" << a.Denominator();	
	return out;
}

istream& operator>>(istream& input, Rational& a)
{		
	char div;
	int x, y;
	input >> x >> div >> y;
	if (input && div == '/')
	{
		a = { x, y };
	}
	return input;
}

bool operator < (const Rational& a, const Rational& b)  {
	return (a.Numerator() * b.Denominator() < a.Denominator() * b.Numerator());
}

bool operator > (const Rational& a, const Rational& b)  {
	return (a.Numerator() * b.Denominator() > a.Denominator() * b.Numerator());
}


int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
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
