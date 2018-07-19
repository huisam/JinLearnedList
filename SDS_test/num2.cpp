#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

bool check_field(vector<vector<int>> &field, int a, int b)
{
	bool water = false;
	bool mountain = false;
	bool grass = false;

	if (field[a][b] == 0 || field[a - 1][b] == 0 || field[a][b - 1] == 0 || field[a + 1][b] == 0 || field[a][b + 1] == 0 ||
		field[a - 1][b - 1] == 0 || field[a + 1][b + 1] == 0 || field[a - 1][b + 1] == 0 || field[a + 1][b - 1] == 0)
		return false;

	if (field[a][b] == 1 || field[a - 1][b] == 1 || field[a][b - 1] == 1 || field[a + 1][b] == 1 || field[a][b + 1] == 1 ||
		field[a - 1][b - 1] == 1 || field[a + 1][b + 1] == 1 || field[a - 1][b + 1] == 1 || field[a + 1][b - 1] == 1)
		water = true;

	if (field[a][b] == 2 || field[a - 1][b] == 2 || field[a][b - 1] == 2 || field[a + 1][b] == 2 || field[a][b + 1] == 2 ||
		field[a - 1][b - 1] == 2 || field[a + 1][b + 1] == 2 || field[a - 1][b + 1] == 2 || field[a + 1][b - 1] == 2)
		mountain = true;
	
	if (field[a][b] == 3 || field[a - 1][b] == 3 || field[a][b - 1] == 3 || field[a + 1][b] == 3 || field[a][b + 1] == 3 ||
		field[a - 1][b - 1] == 3 || field[a + 1][b + 1] == 3 || field[a - 1][b + 1] == 3 || field[a + 1][b - 1] == 3)
		grass = true;

	return (water && mountain && grass);
}

int main()
{
	ifstream fileopen;
	fileopen.open("test2.txt");
	int test_case,N;
	fileopen >> test_case;


	for (int i = 0; i < test_case; i++)
	{
		int house = 0;
		fileopen >> N;
		vector<vector<int>> field(N+2,vector<int>(N+2));
		for (int a = 0; a < N + 2; a++)
			for (int b = 0; b < N + 2; b++)
				field[a][b] = 4;

		for (int a = 1; a < N+1; a++)
			for (int b = 1; b < N+1; b++)
				fileopen >> field[a][b];

		for (int a = 1; a < N+1; a++)
			for (int b = 1; b < N+1; b++)
			{
				if (!check_field(field, a, b))
				{
					continue;
				}
				else
					house++;
			}
		
		cout << "#" << i + 1 << " " << house << endl;
		vector<vector<int>>().swap(field);
		
	}

	return 0;
}
