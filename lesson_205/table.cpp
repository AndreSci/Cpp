#include "test_runner.h"

using namespace std;

template<typename T>
class Table
{
public:
	Table(size_t a, size_t b)
	{
		Resize(a, b);
	}
	void Resize(size_t a, size_t b)
	{
		date.resize(a);
		for (vector<T>& w : date)
		{
			w.resize(b);
		}
	}
	const vector<T> operator [] (size_t a) const 
	{
		return date[a];
	}
	vector<T>& operator[](size_t a)
	{
		return date[a];
	}
	pair<size_t, size_t> Size() const {
		size_t t1 = date.size();
		size_t t2;
		if (date.empty())
		{
			t2 = 0;
		}
		else {
			t2 = date[0].size();
		}
		return { t1,t2 };
	}

private:
	vector<vector<T>> date;
};
void TestTable() {
	Table<int> t(1, 1);

	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}
