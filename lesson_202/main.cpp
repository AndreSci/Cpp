#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;
ostream& operator<< (ostream& os, const Date& s) {

	return os << "{" << s.year << '-' << s.month << '-' << s.day << "}";
}
ostream& operator<< (ostream& os, const Time& s) {

	return os << "{" << s.hours << ':' << s.minutes << "}";
}
bool operator==(const Date& lhs, const Date& rhs)
{
	return vector<int>{lhs.year, lhs.month, lhs.day} == vector<int>{rhs.year, rhs.month, rhs.day};
}
bool operator==(const Time& lhs, const Time& rhs)
{
	return vector<int>{lhs.hours, lhs.minutes} == vector<int>{rhs.hours, rhs.minutes};
}

bool operator<(const Date& lhs, const Date& rhs)
{
	return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
}
bool operator<(const Time& lhs, const Time& rhs)
{
	return vector<int>{lhs.hours, lhs.minutes} < vector<int>{rhs.hours, rhs.minutes};
}
istream& operator>>(istream& str, Date& date) {
	str >> date.year;
	str.ignore(1);
	str >> date.month;
	str.ignore(1);
	str >> date.day;
	return str;
}
istream& operator>>(istream& str, Time& time) {
	str >> time.hours;
	str.ignore(1);
	str >> time.minutes;
	return str;
}

void UpdateTicket(AirlineTicket& ticket, const string& field, const map<string, string>& updates) {
	map<string, string>::const_iterator it;

	it = updates.find(field);
	if (it != updates.end() && field =="to") {
		ticket.to = it->second;
	}

	it = updates.find(field);
	if (it != updates.end() && field == "from") {
		ticket.from = it->second;
	}
	it = updates.find(field);
	if (it != updates.end() && field == "airline") {
		ticket.airline = it->second;
	}

	it = updates.find(field);
	if (it != updates.end() && field == "price") {
		istringstream is(it->second);
		is >> ticket.price;
	}
	it = updates.find(field);
	if (it != updates.end() && field == "departure_date") {
		istringstream is(it->second);
		is >> ticket.departure_date;
	}
	it = updates.find(field);
	if (it != updates.end() && field == "departure_time" ) {
		istringstream is(it->second);
		is >> ticket.departure_time;
	}

	it = updates.find(field);
	if (it != updates.end() && field == "arrival_time") {
		istringstream is(it->second);
		is >> ticket.arrival_time;
	}
	it = updates.find(field);
	if (it != updates.end() && field == "arrival_date") {
		istringstream is(it->second);
		is >> ticket.arrival_date;
	}
}

#define UPDATE_FIELD(ticket, field, values)	UpdateTicket(ticket, #field, values)

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
