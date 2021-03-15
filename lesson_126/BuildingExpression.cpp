#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int main()
{
	int x(0);
	unsigned int N(0);
	string result;
	vector<string> command;
	vector<int> num;

	cin >> x;
	cin >> N;

	if (N == 0)
	{
		cout << x << endl;
		system("pause");
		return 0;
	}
	for (int i(0); i < N; i++)
	{
		string a;
		int b;
		cin >> a;
		cin >> b;
		command.push_back(a);
		num.push_back(b);
	}

	for(int i(0); i <N; i++)
		result += "(";
	result += to_string(x);
	result += ")";

	for (int i(0); i < N; i++)
	{
		result += " ";
		result += command[i];
		result += " ";
		result += to_string(num[i]);
		if (i != N - 1)
		{
			result += ")";
		}
	}

	cout << result << endl;

	system("pause");
	return 0;
}
