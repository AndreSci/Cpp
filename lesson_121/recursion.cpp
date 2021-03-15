#include <iostream>
#include <stdio.h>

using namespace std;

void print(const int *v, const int size)
{
	if (v != 0) {
		for (int i = 0; i < size; i++) {
			cout << v[i] << ' ';
		}
		cout << endl;
	}
}


void permute(int *v, const int start, const int n)
{
	if (start == n - 1) {
		print(v, n);
	}
	else {
		for (int i = start; i < n; i++) {
			int tmp = v[i];

			v[i] = v[start];
			v[start] = tmp;
			permute(v, start + 1, n);
			v[start] = v[i];
			v[i] = tmp;
		}
	}
}


int main()
{
	int N(0);
	cin >> N;


	int *Array = new int[N];

	for (int i(0); i < N; i++)
	{
		Array[i] = N-i;
	}
	permute(Array, 0, sizeof(Array) -1);
	

	return 0;
}
