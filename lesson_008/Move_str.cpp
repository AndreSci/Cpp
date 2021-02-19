#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (int i(0); i < source.size(); i++)
	{
		destination.push_back(source[i]);
	}
	source.clear();
}


int main()
{
	vector<string> source;
	vector<string> destination;
	string word;
	while (cin >> word)
	{
		source.push_back(word);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	while (cin >> word)
	{
		destination.push_back(word);
		if (cin.get() == '\n')
		{
			break;
		}
	}


	MoveStrings(source, destination);

	for (int i(0); i < destination.size(); i++)
	{
		cout << destination[i] << " ";
	}

	return 0;
}
