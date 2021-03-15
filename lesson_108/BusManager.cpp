#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string temp;
	is >> temp;
	q.stops.clear();
	if (temp == "NEW_BUS")
	{
		is >> q.bus;
		int stop_count;
		q.type = QueryType::NewBus;
		is >> stop_count;

		for (int i(0); i < stop_count; i++) {
			is >> q.stop;
			q.stops.push_back(q.stop);
		}
	}
	else if (temp == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (temp == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (temp == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}	
	return is;
}

struct BusesForStopResponse {
	string stop;
	vector<string> bus_resp;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.bus_resp.empty()) {
		cout << "No stop";
	}
	else {
		for (const string& bus : r.bus_resp) {
			cout << bus << " ";			
		}
	}
	return os;
}

struct StopsForBusResponse {
	string bus;
	map<string, vector<string>> stop_resp;
	map<string, vector<string>> bus_resp;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stop_resp.count(r.bus)== 0) {
		os << "No bus" << endl;
	}
	else {
		for (const string& stop : r.stop_resp.at(r.bus)) {
			os << "Stop " << stop << ":";
			int stop_index(0);
			for (const auto& w : r.stop_resp)
			{
				for (const auto & s : w.second)
				{
					if (s == stop)
						stop_index++;
				}
			}
			if (stop_index == 1) {
				os << " no interchange" << endl;
			}
			else {
				for (const auto& other_bus : r.bus_resp.at(stop)) {
					if (r.bus != other_bus) {
						os << " " << other_bus;						
					}
				}
				os << endl;		// ( os == cout ) "ostream& os" в этом случаи endl;  не будет дублироваться при выводе когда строка заканчивается
			}
		}
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> stops_to_bus;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.stops_to_bus.empty()) {
		os << "No buses" << endl;
	}
	else {
		int index(0);
		for (const auto& bus_item : r.stops_to_bus) {
			os << "Bus " << bus_item.first << ":";
			for (const string& stop : bus_item.second) {
				os << " " << stop;
			}
			os << endl;
		}
	}
	return os;
}

class BusManager {
private:
	map<string, BusesForStopResponse> buses_to_stop;
	StopsForBusResponse stops_to_bus;		
	AllBusesResponse All_bus;

public:
	void AddBus(const string& bus, const vector<string>& stops) {
		stops_to_bus.stop_resp[bus] = stops;		
		All_bus.stops_to_bus[bus] = stops;
		
		for (string stop : stops) {
			buses_to_stop[stop].bus_resp.push_back(bus);
			stops_to_bus.bus_resp[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		if (buses_to_stop.count(stop) == 0) {
			BusesForStopResponse Empty_stop;
			return Empty_stop;
		}
		else
			return buses_to_stop.at(stop);
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse Empty_bus;
		if (stops_to_bus.stop_resp.count(bus) == 0) {
			return Empty_bus;
		}
		else
		{
			Empty_bus.bus = bus;
			Empty_bus.bus_resp = stops_to_bus.bus_resp;
			Empty_bus.stop_resp = stops_to_bus.stop_resp;
			return StopsForBusResponse{ Empty_bus };
		}
	}

	AllBusesResponse GetAllBuses() const {
		return All_bus;
	}	
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;				// >> Принимает строку и с помощью оператора >> распределяет текcт по значениям
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
