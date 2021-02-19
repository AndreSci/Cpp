#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool myfunction(int i, int j)
{ 
	i = abs(i);
	j = abs(j);
	
	return (i < j); 
}

int main() 
{
	int N(0), a(0);
	vector<int> A;

	cin >> N;
	for (int i(0); i < N; i++)
	{
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end(), myfunction);

	for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		cout << *it << ' ';

	return 0;
}
