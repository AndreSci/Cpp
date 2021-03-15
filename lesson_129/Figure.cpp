#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

class Figure	// базовый
{
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Triangle : public Figure //периметр P=a+b+c	//	S = a*b/2
{
public:
	Triangle(const string& name, const double& a, const double& b, const double& c) 
		: _name(name), _a(a),_b(b), _c(c)  {}
	virtual string Name() override {
		return _name;
	}
	virtual double Perimeter() override {
		double P = _a + _b + _c;
		return P;
	}
	virtual double Area() override {
		double s = (_a + _b +_c) / 2;
		double area_triangle = sqrt((s*(s - _a)*(s - _b)*(s - _c)));

		return area_triangle;
	}

private:
	string _name;
	double _a, _b, _c;
};
class Rect : public Figure		//периметр P=2×(a + b)	//	S = a*b
{
public:
	Rect(const string& name, const double& a, const double& b)
		: _name(name), _a(a), _b(b) {}

	virtual string Name() override {
		return _name;
	}
	virtual double Perimeter() override {
		double P = 2 * (_a + _b);
		return P;
	}
	virtual double Area() override {
		double S = _a * _b;
		return S;
	}

private:
	string _name;
	double _a, _b;
};
class Circle : public Figure	//периметр P= 2 п r	  ... п= 3.14	// S = п R^2
{
public:
	Circle(const string& name, const double& r)
		: _name(name), _r(r) {}
	virtual string Name() override {
		return _name;
	}
	virtual double Perimeter() override {
		double P = 2 * 3.14*_r;
		return P;
	}
	virtual double Area() override {
		double S = 3.14*(_r*_r);
		return S;
	}

private:
	string _name;
	double _r;
};


shared_ptr<Figure> CreateFigure(istringstream& is)
{
	string figure;
	is >> figure;
	if (figure == "RECT")
	{
		double a, b;
		is >> a;
		is >> b;
		return make_shared<Rect> ("RECT", a, b);
	}
	else if (figure == "TRIANGLE")
	{
		double a, b,c;
		is >> a;
		is >> b;
		is >> c;
		return make_shared<Triangle>("TRIANGLE", a, b,c);
	}
	else if (figure == "CIRCLE")
	{
		double r;
		is >> r;
		return make_shared<Circle>("CIRCLE", r);
	}
	return make_shared<Circle>("CIRCLE", 0);
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
