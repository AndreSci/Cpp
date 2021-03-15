#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal(const string& name) : Name(name){}

	const string Name;
};


class Dog : public Animal {
public:
	Dog(const string& name = "animal") : Animal(name) {}

	void Bark() {
		cout << Name << " barks: woof!" << endl;
	}
};

int main()
{
	Dog d("Dog");
	d.Bark();


	system("pause");
	return 0;
}
