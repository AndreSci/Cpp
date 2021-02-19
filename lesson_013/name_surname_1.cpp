#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class Person
{
public:
	void ChangeFirstName(int year, const string& first_name)
	{
		f_name[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name)
	{
		l_name[year] = last_name;
	}
	string GetFullName(int year)
	{
		string result_f, result_l;

		for (auto f : f_name)
		{
			if (f.first <= year)
				result_f = f.second;
		}
		for (auto l : l_name)
		{
			if (l.first <= year)
			{
				result_l = l.second;
			}
		}
		if (result_f.empty() && result_l.empty())
			return "Incognito";
		else if (result_f.empty())
			return result_l + " with unknown first name";
		else if (result_l.empty())
			return result_f + " with unknown last name";
		else
			return result_f + " " + result_l;
	}
	string GetFullNameWithHistory(int year)
	{
		vector<string> f_name_his;
		vector<string> l_name_his;
		vector<string> temp;
		string result_f = "", result_l = "", result_return;
		int index(0);

		
		for (auto f : f_name)
		{
			if (f.first <= year)
			{
				result_f = f.second;				// Evgeny
				f_name_his.push_back(f.second);		// Eugene - Evgeny - Evgeny 
			}
		}
		for (auto l : l_name)
		{
			if (l.first <= year)
			{
				result_l = l.second;
				l_name_his.push_back(l.second);
			}
		}	

		if (result_f.empty() && result_l.empty())
			return "Incognito";

		/////////////////////////////////////////////////////////////////////////////////////////////
		reverse(begin(f_name_his), end(f_name_his));	// перевернем массив имен // Evgeny - Eugene

		if (!f_name_his.empty())
		{			
			for (int i(0); i < f_name_his.size() - 1; i++)
			{				
				if (f_name_his[i] == f_name_his[i + 1])
				{
					f_name_his[i].erase();					// Сравниваем и если они схожи удаляем первый элемент
				}
			}
		}
		if (!f_name_his.empty())
		for (auto w : f_name_his)		// Убираем пустые элементы массива(вектора)
		{
			if (!w.empty())
				temp.push_back(w);
		}
		f_name_his = temp;
		temp.clear();
		
		if (!f_name_his.empty())
		if (result_f == f_name_his[0])	// Убираем если первый элемент вектора схож с result_f
		{
			f_name_his[0].erase();
			for (auto w : f_name_his)		// Убираем пустые элементы массива(вектора)
			{
				if (!w.empty())
					temp.push_back(w);
			}
			f_name_his = temp;
			temp.clear();
		}		
		///////////////////////////////////////////////////////
		////  result_f
		
		if (!f_name_his.empty())
		for (auto w : f_name_his)
		{		
			if (index == 0)
			{
				result_f = result_f + " (" + w;
				index++;
			}
			else
			result_f = result_f + ", " + w;
		}
		if(index > 0)
			result_f = result_f + ")";
		index = 0;
		////////////////////////////////////////////////////////
	
		
		reverse(begin(l_name_his), end(l_name_his));

		
		if (!l_name_his.empty())
		{
			for (int i(0); i < l_name_his.size() - 1; i++)
			{
				if (l_name_his[i] == l_name_his[i + 1])
				{
					l_name_his[i].erase();	
				}
			}
		}
		
		if (!l_name_his.empty())
		for (auto w : l_name_his)	
		{
			if (!w.empty())
				temp.push_back(w);
		}
		l_name_his = temp;
		temp.clear();

		
		if(!l_name_his.empty())
		if (result_l == l_name_his[0])		// Убираем если первый элемент вектора схож с result_l
		{
			l_name_his[0].erase();
			for (auto w : l_name_his)	
			{
				if (!w.empty())
					temp.push_back(w);
			}
			l_name_his = temp;
			temp.clear();
		}
		
		///////////////////////////////////////////////////////
		if (!l_name_his.empty())
			for (auto w : l_name_his)
			{
				if (index == 0)
				{
					result_l = result_l + " (" + w;
					index++;
				}
				else
					result_l = result_l + ", " + w;
			}
		if (index > 0)
			result_l = result_l + ")";
		index = 0;

		////////////////////////////////////////////////////////
		if (result_f.empty())
			return result_l + " with unknown first name";
		else if (result_l.empty())
			return result_f + " with unknown last name";
		else
			return result_f + " " + result_l;
		////////////////////////////////////////////////////////
	}
private:

	map<int, string> f_name;
	map<int, string> l_name;
};

