#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

int GreatestCommonDivisor(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GreatestCommonDivisor(b, a % b);
	}
}

void Rational_Test()
{
	{
		const Rational r(3, 10);
		AssertEqual(r.Numerator(), 3, "wrong 1 - Numerator");
		AssertEqual(r.Denominator(), 10, "wrong 1 - Denominator");
	}
	{
		const Rational r(8, 12);
		AssertEqual(r.Numerator(), 2, "wrong 2 - Numerator");
		AssertEqual(r.Denominator(), 3, "wrong 2 - Denominator");
	}
	{
		const Rational r(-4, 6);
		AssertEqual(r.Numerator(), -2, "wrong 3 - Numerator");
		AssertEqual(r.Denominator(), 3, "wrong 3 - Denominator");
	}
	{
		const Rational r(4, -6);
		AssertEqual(r.Numerator(), -2, "wrong 4 - Numerator");
		AssertEqual(r.Denominator(), 3, "wrong 4 - Denominator");
	}
	{
		const Rational r(0, 15);
		AssertEqual(r.Numerator(), 0, "wrong 5 - Numerator");
		AssertEqual(r.Denominator(), 1, "wrong 5 - Denominator");
	}
	{
		const Rational r(4, 22);
		AssertEqual(r.Numerator(), 2, "wrong 6 - Numerator");
		AssertEqual(r.Denominator(), 11, "wrong 6 - Denominator");
	}
	{
		const Rational r(-4, -6);
		AssertEqual(r.Numerator(), 2, "wrong 7 - Numerator");
		AssertEqual(r.Denominator(), 3, "wrong 7 - Denominator");
	}
	{
		const Rational r(-1, -3);
		AssertEqual(r.Numerator(), 1, "wrong 8 - Numerator");
		AssertEqual(r.Denominator(), 3, "wrong 8 - Denominator");
	}
	{
		const Rational r(-2, -3);
		AssertEqual(r.Numerator(), 2, "wrong 9 - Numerator");
		AssertEqual(r.Denominator(), 3, "wrong 9 - Denominator");
	}
	{
		const Rational r(0, -15);
		AssertEqual(r.Numerator(), 0, "wrong 10 - Numerator");
		AssertEqual(r.Denominator(), 1, "wrong 10 - Denominator");
	}
	{
		Rational Default;
		AssertEqual(Default.Numerator(), 0, "wrong 11 - Numerator");
		AssertEqual(Default.Denominator(), 1, "wrong 11 - Denominator");
	}
}


int main() {
	TestRunner runner;
	runner.RunTest(Rational_Test, "Rational_Test");

	return 0;
}
