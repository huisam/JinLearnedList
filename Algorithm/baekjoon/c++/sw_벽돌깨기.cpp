#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int n;
	for (int a = 1; a <= n; a++)
	{
		int n, w, h;
		cin >> n >> w >> h;
		vector<vector<int>> map(h, vector<int>(w, 0));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

	}
}