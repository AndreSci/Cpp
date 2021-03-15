/*/////////////////////////////////////////
Author - AndrewSci					///////
Name - code refactoring				///////
*//////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class People
{
public:
	People(const string& name, const string& status) : Name(name), Status(status) {}

	string isName() const { return Name; }
	string Whois() const { return Status; }
	virtual void Walk(const string& destination) const = 0;

protected:
	const string Name;
	const string Status;
};

class Student : public People {
public:
	Student(const string& name, const string& favouriteSong) : People(name, "Student"), FavouriteSong(favouriteSong){}

	void Learn() {
		cout << Whois() << ": " << isName() << " learns" << endl;
	}

	virtual void Walk(const string& destination) const override {
		cout << Whois() << ": " << isName() << " walks to: " << destination << endl;
		cout << Whois() << ": " << isName() << " sings a song: " << FavouriteSong << endl;
	}

	void SingSong() {
		cout << Whois() << ": " << isName() << " sings a song: " << FavouriteSong << endl;
	}

private:
	const string FavouriteSong;
};


class Teacher : public People {
public:
	Teacher(const string& name, const string& subject) : People(name, "Teacher"), Subject(subject){}

	void Teach() {
		cout << Whois() << ": " << isName() << " teaches: " << Subject << endl;
	}

	virtual void Walk(const string& destination) const override{
		cout << Whois() << ": " << isName() << " walks to: " << destination << endl;
	}

private:
	const string Subject;
};


class Policeman : public People {
public:
	Policeman(const string& name) : People(name, "Policeman"){}

	void Check(const People& p) {
		cout << Whois() << ": " << isName() << " checks " << p.Whois() <<". " << p.Whois() << "'s name is: " << p.isName() << endl;
	}

	virtual void Walk(const string& destination) const override {
		cout << Whois() << ": " << isName() << " walks to: " << destination << endl;
	}
};

void VisitPlaces(const People& t, const vector<string>& places) {
	for (const auto& p : places) {
		t.Walk(p);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });

	return 0;
}
