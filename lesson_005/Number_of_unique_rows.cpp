#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int N(0);
	set<string> Strings;
	string word;

	cin >> N;
	for (int i(0); i < N; i++)
	{
		cin >> word;
		Strings.insert(word);
	}
	cout << Strings.size() << endl;

	return 0;
}
