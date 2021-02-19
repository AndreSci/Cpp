#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
	ReversibleString();
	
	ReversibleString(const string& w)
	{
		word = w;
	}
	void Reverse()
	{
		reverse(word.begin(), word.end());
	}
	string ToString() const
	{
		return word;
	}

private:
	string word;
};
ReversibleString::ReversibleString()
{}
