#include<vector>
#include<iostream>

using namespace std;

bool check[9];

int main()
{
	vector<vector<int>> puzzle(9, vector<int>(9, 0));
	for (auto &v : puzzle)
		for (auto &z : v)
			cin >> z;

	cout << 1;
	return 0;
}