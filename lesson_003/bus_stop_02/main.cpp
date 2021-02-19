#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int Q(0), STEP(0), N(0), bus_step(0);
	map<int, vector<string>> All_bus;
	string bus;
	vector<string> string_stop;

	cin >> Q;
	while (Q > STEP)
	{
		cin >> N;
		bus_step++;
		for (int i(0); i < N; i++)
		{
			cin >> bus;
			
			string_stop.push_back(bus);
		}
		bool step_test_bus = false;

		for (int i(0); i < All_bus.size(); i++)
		{
			if (All_bus[i] == string_stop && step_test_bus == false)
			{
				cout << "Already exists for " << i << endl;
				step_test_bus = true;
				bus_step--;
			}			
		}
		if (step_test_bus == false)
		{
			All_bus[bus_step].insert(All_bus[bus_step].end(), string_stop.begin(), string_stop.end());
			cout << "New bus " << bus_step << endl;
		}	

		string_stop.clear();
		STEP++;
	}

	return 0;
}
