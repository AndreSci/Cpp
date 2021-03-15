#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename IT>
void PringRange(IT range_begin, IT range_end)
{
	for (auto it = range_begin; it != range_end; ++it)
	{
		if (it != range_begin)
			cout << " ";
		cout << *it;
	}
	cout << endl;
}

void PrintVectorPart(const vector<int>& numbers)
{
	auto result = find_if(begin(numbers), end(numbers),
		[](const int& num)
		{
		return num < 0;
		}
	);
	if (result != end(numbers)) {
		vector<int> numbs;
		for (auto w : numbers)
		{
			if (w == result[0])
			{
				break;
			}
			numbs.push_back(w);
		}
		reverse(begin(numbs), end(numbs));
		PringRange(begin(numbs), end(numbs));
	}
	else
	{
		vector<int> numbs;
		for (auto w : numbers)
		{			
			numbs.push_back(w);
		}
		reverse(begin(numbs), end(numbs));
		PringRange(begin(numbs), end(numbs));
	}
}


int main()
{
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	PrintVectorPart({ 6, 1, 8, 5, 4 });


	system("pause");
	return 0;
}
