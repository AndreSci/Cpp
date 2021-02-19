#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> value;

	for (auto v : m)
	{
		value.insert(v.second);
	}
	return value;
}
