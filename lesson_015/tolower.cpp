#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool Tolower(string i, string j)
{
	int Size = i.size();			
	for (int x(0); x< Size; x++)
	{
		if (tolower(i[x]) < tolower(j[x]))
			return (tolower(i[x]) < tolower(j[x]));
		else if (tolower(i[x]) > tolower(j[x]))
			return (tolower(i[x]) < tolower(j[x]));
	}
}

int main()
{
	int N(0);
	vector<string> S;
	string word;

	cin >> N;
	for (int i(0); i < N; i++)
	{
		cin >> word;
		S.push_back(word);
	}

	sort(S.begin(), S.end(), Tolower);

	for (vector<string>::iterator it = S.begin(); it != S.end(); ++it)
	{
		cout << *it << " ";
	}
	return 0;
}
