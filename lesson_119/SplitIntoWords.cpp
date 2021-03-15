#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;


vector<string> SplitIntoWords(const string& s)
{
	vector<string> words;
	stringstream word(s);
	string word_push;
	while (word)
	{
		word >> word_push;
		words.push_back(word_push);
	}
	words.pop_back();

	return words;
}


int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	system("pause");
	return 0;
}
