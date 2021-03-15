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

bool IsPalindrom(const string& str) {
	string s = str;
	for (size_t i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

void Test_Palindrom()
{
	AssertEqual(IsPalindrom("madam"), true, "wrong answer 1");
	AssertEqual(IsPalindrom("Madam"), false, "wrong answer 2");
	AssertEqual(IsPalindrom("Andrew"), false, "wrong answer 3");
	AssertEqual(IsPalindrom("level"), true, "wrong answer 4");
	AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "wrong answer 5");
	AssertEqual(IsPalindrom("ABsioisBA"), true, "wrong answer 6");
	AssertEqual(IsPalindrom("ABsi oisBA"), false, "wrong answer 7");
	AssertEqual(IsPalindrom("ABoBA"), true, "wrong answer 8");
	AssertEqual(IsPalindrom("  "), true, "wrong answer 9");
	AssertEqual(IsPalindrom("a"), true, "wrong answer 10");
	AssertEqual(IsPalindrom("aba aba"), true, "wrong answer 11");
	AssertEqual(IsPalindrom("maam"), true, "wrong answer 12");
	AssertEqual(IsPalindrom("madama"), false, "wrong answer 13");
	AssertEqual(IsPalindrom("amadam"), false, "wrong answer 14");
	AssertEqual(IsPalindrom("ma  am"), true, "wrong answer 15");
	AssertEqual(IsPalindrom("level level"), true, "wrong answer 16");
	AssertEqual(IsPalindrom("leveL Level"), true, "wrong answer 17");
	AssertEqual(IsPalindrom("lEvel lEvel"), false, "wrong answer 18");
	AssertEqual(IsPalindrom(" level "), true, "wrong answer 19");
	AssertEqual(IsPalindrom(" level"), false, "wrong answer 20");
	AssertEqual(IsPalindrom("level "), false, "wrong answer 21");
	AssertEqual(IsPalindrom(""), true, "wrong answer 22");
	AssertEqual(IsPalindrom("l eve l"), true, "wrong answer 23");


}

int main() {
	TestRunner runner;
	runner.RunTest(Test_Palindrom, "Test_Palindrom");

	return 0;
}
