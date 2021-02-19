#include <iostream>

using namespace std;


int UpdateIfGreater(const int a, int& b)
{
	if (a > b)
	{
		b = a;
	}
	return b;
}

int main()
{
	int first(0);
	int second(0);

	cin >> first >> second;

	UpdateIfGreater(first, second);

	cout << second;

	return 0;
}
