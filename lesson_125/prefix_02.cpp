#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

bool cmp_up(const string& prefix, const string& word)
{
	int p = static_cast<int>(prefix.size());
	string w1;
	//if (p <= static_cast<int>(word.size()))
		for (int i(0); i < p; i++)
		{
			w1 += word[i];
		}
	return w1 > prefix;
}

bool cmp_low(const string& word, const string& prefix)
{
	int p = static_cast<int>(prefix.size());
	string w1;
	//if(p <= static_cast<int>(word.size()))
	for (int i(0); i < p; i++)
	{
		w1 += word[i];
	}
	return w1 < prefix;
}

string t_words(const string& word, const string& prefix)
{
	int p = static_cast<int>(prefix.size());
	string w1;
	//if (p <= static_cast<int>(word.size()))
		for (int i(0); i < p; i++)
		{
			w1 += word[i];
		}
	if (w1 == prefix)
		return word;
	else
		return "";
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix)
{
	string s;
	auto one = lower_bound(range_begin, range_end, prefix, cmp_low);
	if (one != range_end)
	{		
		s = t_words(*one, prefix);
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
	const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << endl;

	system("pause");
	return 0;
}
