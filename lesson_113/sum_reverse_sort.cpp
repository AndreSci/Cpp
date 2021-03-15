#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y)
{
	return x + y;
}

string Reverse(string s)
{
	string str = s;
	reverse(begin(str), end(str));
	return str;
}

void Sort(vector<int>& nums)
{
	sort(begin(nums), end(nums));

}
