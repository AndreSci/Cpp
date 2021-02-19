#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input("input.txt");
	string value;
	vector<double> values;
	if (input)
	{
		while (getline(input, value))
		{
			values.push_back(stod(value));
		}
	}
	
	cout << fixed << setprecision(3);
	for (auto w : values)
	{
		cout << w << endl;
	}

	return 0;
}
