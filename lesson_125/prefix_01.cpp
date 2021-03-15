#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

bool cmp_up(const char& prefix, const string& word)
{
	return word[0] > prefix;
}

bool cmp_low(const string& word, const char& prefix)
{
	return word[0] < prefix;
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{

	string s;
	auto one = lower_bound(range_begin, range_end, prefix, cmp_low);
	if (one != range_end)
	{		
		s = *one;
		if (s[0] != prefix)
			s.clear();
	}

	if (s.empty())
	{
		auto one_end = lower_bound(range_begin, range_end, prefix, cmp_low);
		return { one_end, one_end };
	}
	auto two = upper_bound(one, range_end, prefix, cmp_up);


	return { one , two };
}

int main()
{
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

	const auto m_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto p_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " <<
		(p_result.second - begin(sorted_strings)) << endl;

	const auto z_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " <<
		(z_result.second - begin(sorted_strings)) << endl;

	system("pause");
	return 0;
}
