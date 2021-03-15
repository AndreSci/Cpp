#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <vector>


using namespace std;

template<typename K, typename V>

V& GetRefStrict(map<K, V>& m, K value)
{
	if (m.find(value) == m.end())
		throw runtime_error("exception happened");
	return  m[value];
}
