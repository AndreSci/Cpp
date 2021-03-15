#include <iostream>
#include <vector>

using namespace std;

int main()
{
	uint64_t N(0), Density_R(0), W(0), H(0), D(0);
	uint64_t Volume_R(0), Result(0);
	vector<vector<uint64_t>> all_cube;

	cin >> N >> Density_R;
	all_cube.assign(N, vector<uint64_t>());

	for (int i(0); i < N; i++)
	{		
		cin >> W >> H >> D;
		all_cube[i].push_back(W);
		all_cube[i].push_back(H);
		all_cube[i].push_back(D);
	}
	// формула нахождения массы параллелепипеда плотность*обьем (Density_R*Volume_R) - обьем Volume = W*H*D
	for (int i(0); i < static_cast<int>(all_cube.size()); i++)
	{
		Volume_R += all_cube[i][0] * all_cube[i][1] * all_cube[i][2];
	}
	Result = Volume_R * Density_R;

	cout << Result << endl;

	return 0;
}
