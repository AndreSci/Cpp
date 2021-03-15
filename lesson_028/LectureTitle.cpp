#include <iostream>
#include <string>


using namespace std;

struct Specialization
{
	string text;
	explicit Specialization(string new_text)
	{
		text = new_text;
	}
};

struct Course
{
	string text;
	explicit Course(string new_text)
	{
		text = new_text;
	}
};

struct Week
{
	string text;
	explicit Week(string new_text)
	{
		text = new_text;
	}
};


struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization s, Course c, Week w)
	{
		specialization = s.text;
		course = c.text;
		week = w.text;
	}
};
