#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

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
		if (denominator == 0) 
		{
			// бросаем исключение в случае нулевого знаменателя
			throw invalid_argument("Invalid argument");
		}

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
	if (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator())
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
	// проверяем делитель на 0 (что равносильно проверке на 0 его числителя)
	if (b.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
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

bool operator < (const Rational& a, const Rational& b) {
	return (a.Numerator() * b.Denominator() < a.Denominator() * b.Numerator());
}

bool operator > (const Rational& a, const Rational& b) {
	return (a.Numerator() * b.Denominator() > a.Denominator() * b.Numerator());
}


int main() {
	
	int X(0), Y(1);
	char oper, oper2;

	cin >> X >> oper >> Y;
	try {
		Rational r(X, Y);
		cin >> oper2;

		cin >> X >> oper >> Y;
		const Rational r2(X, Y);

		Rational r3;

		try
		{
			switch (oper2)
			{
			case '+':  r3 = r + r2; break;
			case '-':  r3 = r - r2; break;
			case '*':  r3 = r * r2; break;
			case '/':  r3 = r / r2; break;
			}
			cout << r3.Numerator() << "/" << r3.Denominator() << endl;
		}
		catch (domain_error& dv)
		{
			cout << dv.what() << endl;
		}
	}
	catch (invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
