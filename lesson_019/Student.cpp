#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int ui;

struct Student
{
	Student();
	Student(const string& n, const string& s, const ui& d, const ui& m, const ui& y)
	{
		name = n;
		surname = s;
		day = d;
		month = m;
		year = y;
	}
	string name;
	string surname;
	ui day;
	ui month;
	ui year;
};

int main()
{
	int N(0), M(0), K(0);
	string command, name, surname;
	ui Day(0), Month(0), Year(0);
	vector<Student> Students;

	cin >> N;
	for (int i(0); i < N; i++)
	{
		cin >> name >> surname >> Day >> Month >> Year;

		Student stud(name, surname, Day, Month, Year);
		Students.push_back(stud);
	}
	cin >> M;

	for (int i(0); i < M; i++)
	{
		cin >> command >> K;
		if (K > N || N == 0 || K == 0)
		{
			cout << "bad request" << endl;
		}
		else if (command == "name")
		{
			cout << Students[K - 1].name << " " << Students[K - 1].surname << endl;
		}
		else if (command == "date")
		{
			cout << Students[K - 1].day << "." << Students[K - 1].month << "." << Students[K - 1].year << endl;
		}
		else
			cout << "bad request" << endl;
	}

	return 0;
}
