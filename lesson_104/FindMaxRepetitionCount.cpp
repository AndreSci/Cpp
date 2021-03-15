#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <utility>
#include <algorithm>


bool operator<(const Region& lhs, const Region& rhs) 

{

	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);

}


int FindMaxRepetitionCount(const vector<Region>& regions) 
{
	int result = 0;
	map<Region, int> reg_count_max;
	for (int i(0); i < static_cast<int>(regions.size()); i++)
	{
		reg_count_max[regions[i]] += 1;
	}
	for (auto w : reg_count_max)
	{
		if (w.second > result)
			result = w.second;
	}

	return result;
}
