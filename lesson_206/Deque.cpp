#include <iostream>
#include <vector>

using namespace std;

#define FRONT_BACK(lhs, rhs)					\
		if (lhs.empty()) return rhs.front();	\
		else return lhs.back();					\

template<typename T>
class Deque
{
public:
	Deque()
	{
		first.resize(0);
		second.resize(0);
	}

	T& Front()
	{
		FRONT_BACK(first, second);
	}
	const T& Front() const
	{
		FRONT_BACK(first, second);
	}
	T& Back()
	{
		FRONT_BACK(second, first);
	}
	const T& Back() const
	{
		FRONT_BACK(second, first);
	}

	bool Empty() const		// в условии написано что он КОНСТАНТНЫЙ
	{
		return { first.empty() && second.empty() };
	}

	void PushFront(const T& item)
	{
		first.push_back(item);
	}

	void PushBack(const T& item)
	{
		second.push_back(item);
	}

	const size_t Size() const {
		return first.size() + second.size();
	}	

	T& operator[](size_t index)
	{
		return At(index);
	}
	const T& operator[](size_t index) const
	{
		return At(index);
	}

	const T& At(size_t index) const
	{
		return At(index);
	}

	T& At(size_t index)
	{
		if (index < first.size())
		{
			return first[(first.size() - 1) -  index]; // определение элемента считается с конца вектора
		}
		else if ((index - first.size()) < second.size())
		{
			return second[index - first.size()];
		}
		else
		{
			throw out_of_range("Error! index >= deque size.");
		}
	}

private:
	vector<T> first;		//Front
	vector<T> second;		//Back
};
