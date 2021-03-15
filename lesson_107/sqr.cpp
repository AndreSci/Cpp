#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template<typename T> T Sqr(T& x);
template <typename T> vector<T>& Sqr(vector<T>& col);
template <typename T> vector<T> operator*(vector<T> col);
template <typename First, typename Second> map<First, Second>& Sqr(map<First, Second>& col);
template <typename First, typename Second> map<First, pair<First, Second>>& Sqr(map<First, pair<First, Second>>& col);
template <typename First, typename Second> pair<First, Second> operator*(pair<First, Second> p1, pair<First, Second> p2);
////////////////////////////////////////

template<typename T>
T Sqr(T& x)
{
	return x * x;
}

template <typename T>
vector<T>& Sqr(vector<T>& col)
{
	for (T& w : col)
	{
		w = Sqr(w);
	}
	return col;
}
template <typename T>
vector<T> operator*(vector<T> col)
{
	for (T& w : col)
	{
		w = Sqr(w);
	}
	return col;
}

template <typename First, typename Second>
map<First,Second>& Sqr(map<First, Second>& col)
{

	for (auto& w : col)
	{
		w.second = Sqr(w.second);
	}
	return col;
}
template <typename First, typename Second>
map<First, pair<First, Second>>& Sqr(map<First, pair<First,Second>>& col)
{

	for (auto& w : col)
	{
		w.second = Sqr(w.second);
	}
	return col;
}

template <typename First, typename Second>
pair<First, Second> operator*(pair<First, Second> p1, pair<First, Second> p2)
{
	First f = p1.first*p2.first;
	Second s = p1.second*p2.second;
	return make_pair(f,s);
}

