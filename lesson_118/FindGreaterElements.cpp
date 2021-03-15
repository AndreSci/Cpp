#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;


template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{	
	vector<T> result;
	for (auto w : elements)
	{
		if(w > border)
		{
			result.push_back(w);
		}
	}
		

	return result;
}


int main() {
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	system("pause");
	return 0;
}
