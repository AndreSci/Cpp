#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	int Q(0), N(0), i(1);
	map<set<string>, int> All_bus;
	set<string> bus_stop;
	string stop;

	cin >> Q;
	for (int j(0); j < Q; j++)
	{
		cin >> N;
		for (int k(0); k < N; k++)
		{
			cin >> stop;
			bus_stop.insert(stop);
		}
		if (All_bus.count(bus_stop) != 0)
		{
			cout << "Already exists for " << All_bus[bus_stop] << endl;
		}
		else
		{
			All_bus[bus_stop] = i;
			cout << "New bus " << All_bus[bus_stop] << endl;
			i++;
		}
		bus_stop.clear();
	}

	return 0;
}
