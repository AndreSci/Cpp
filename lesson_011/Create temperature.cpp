#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n(0);
	cin >> n;

	vector<int> days;

	int tmp(0);
	int index(0);

	for (int i(0); i < n; i++)
	{
		int T(0);
		cin >> T;
		days.push_back(T);
		tmp += T;
	}

	tmp = tmp / n;

	for (int i(0); i < n; i++)
	{
		if (days[i] > tmp)
		{
			index++;
		}
	}
	cout << index << endl;
	for (int i(0); i < n; i++)
	{
		if (days[i] > tmp)
			cout << i << " ";
	}

	return 0;
}
