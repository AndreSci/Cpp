#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int>& v)
{
	reverse(v.begin(), v.end());
}


int main()
{
	vector<int> numbers;

	int tmpm(0);

	while (cin >> tmpm)
	{
		numbers.push_back(tmpm);
		if (cin.get() == '\n')
			break;
	}

	Reverse(numbers);

	for (int i(0); i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}

	return 0;
}
