#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
	int Q(0);
	cin >> Q;
	map<int, set<string>> word_sin;
	int index(0);

	for (int i(0); i < Q; i++)
	{
		string command, word1, word2;
		cin >> command;
		if (command == "ADD")
		{
			index+=1;
			cin >> word1 >> word2;
			word_sin[index].insert(word1);
			word_sin[index].insert(word2);
		}
		else if (command == "COUNT")
		{
			int i(0);
			cin >> word1;
			for(auto w: word_sin)
				i += w.second.count(word1);
			cout << i << endl;
		}
		else if (command == "CHECK")
		{
			int test1(0), test2(2);
			cin >> word1 >> word2;
			for (auto w : word_sin)
			{
				test1 = w.second.count(word1);
				test2 = w.second.count(word2);
				if (test1 == 1 && test2 == 1)
				{
					cout << "YES" << endl;
					break;
				}
				test1 = 0;
				test2 = 2;
			}
			if (test1 != test2)
				cout << "NO" << endl;


		}
	}
	   	  
	return 0;
}
