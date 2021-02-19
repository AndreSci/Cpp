#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Incognizable
{
public:
	Incognizable() {}
	Incognizable(const int& a, const int& b)
	{
		a1 = a;
		a2 = b;
	}
	Incognizable(const string& a, const string& b)
	{
		b1 = a;
		b2 = b;
	}
	Incognizable(const int& a)
	{
		a1 = a;
	}
	Incognizable(const string& a)
	{
		b1 = a;
	}
	Incognizable(const char& a, const char& b)
	{
		c1 = a;
		c2 = b;
	}
	Incognizable(const char& a)
	{
		c1 = a;
		
	}
	Incognizable(const double& a, const double& b)
	{
		d1 = a;
		d2 = b;
	}
	Incognizable(const double& a)
	{
		d1 = a;
	}
private:
	int a1;
	int a2;
	string b1, b2;
	char c1, c2;
	double d1, d2;
};

