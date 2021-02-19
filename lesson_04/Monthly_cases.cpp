#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int Q(0), i(0), DumpID(0), NextM(0);
	string s;								
	int month(0), days(0);
	vector<int> days_in_months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector <vector<string>> cases_in_day(days_in_months[month]);
		
	cin >> Q;

	for (int j = 0; j < Q; j++)
	{
		string operation_code;
		cin >> operation_code;

		if (operation_code == "ADD")
		{
			cin >> i >> s;
		
			cases_in_day[i-1].push_back(s);
		}			   		 

		if (operation_code == "DUMP")
		{
			cin >> i;
			i--;
			if (i >= cases_in_day.size())
				cout << 0;
			else 
			{
				int indexDump = cases_in_day[i].size();
				cout << indexDump << " ";
				
				for (auto out : cases_in_day[i])
				{
					cout << out << " ";
				}
				
			}
			cout << endl;
		}

		if (operation_code == "NEXT")
		{
			NextM++;
			if (NextM > 11)
			{
				NextM = 0;
				month = 0;
				
				cases_in_day.resize(days_in_months[month]);
			}
			else if (days_in_months[month] > days_in_months[month + 1])
			{
				int t3 = days_in_months[month] - days_in_months[month + 1];
				vector<vector<string>> v2(cases_in_day);
				
				month++;
				cases_in_day.resize(days_in_months[month]);
				
				for(int j(0); j < t3; j++)
				for (auto out : v2[cases_in_day.size()+j])
				{
					if(!out.empty())
					cases_in_day[cases_in_day.size() - 1].push_back(out);
				}
			
			}
			else
			{
				month++;
				cases_in_day.resize(days_in_months[month]);
			}
		}




	}
	return 0;
}
