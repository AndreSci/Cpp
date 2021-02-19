#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main()
{
	int Q(5), people(0);
	int worry_peop_step(0);
	cin >> Q;
	int* worry_people = new int [Q];
	for (int e(0); e < Q; e++)
		worry_people[e] = 0;

	vector<string> i;
	string come_quiet;

	for (int p(0); p < Q; p++)
	{
		
		cin >> come_quiet;
		if(come_quiet != "WORRY_COUNT")
			cin >> people;

		if (come_quiet == "COME" && people > 0)
		{
			for (int j(0); j < people; j++)
			{
				i.push_back(" ");
			}
		}

		if (come_quiet == "COME" && people < 0)
		{
			for (int j(0); j > people; j--)
			{
				i.pop_back();
			}
		}

		if (come_quiet == "WORRY")
		{
			i[people - 1] = { "WORRY" };
		}

		if (come_quiet == "WORRY_COUNT")
		{
			for (int f(0); f < i.size(); f++)
			{
				if (i[f] == "WORRY")
					worry_people[worry_peop_step]++;
			}
			worry_peop_step++;			
		}
	}

	for(int g(0); g< worry_peop_step; g++)
		cout << worry_people[g] << endl;

	return 0;
}
