#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <iomanip>

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
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0) {
			throw invalid_argument("invalid argument");
		}
		else if (numerator == 0) {
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
	int q = 1;		// натуральное не может быть 0 или меньше

};

Rational operator/(const Rational& a, const Rational& b)
{
	if ((a.Denominator() == 0 || b.Denominator() == 0) || (a.Numerator() == 0 || b.Numerator() ==0))
		throw domain_error("domain_error");
	Rational div(a.Numerator()*b.Denominator(), a.Denominator()*b.Numerator());

	return div;
}


int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}
