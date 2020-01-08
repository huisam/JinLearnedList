#include<vector>
#include<iostream>

using namespace std;
int n;
int count_num = 0;

void bfs(vector<vector<int>> &map, int x, int y)
{
	if (x > n || y > n)
		return;
	else if (x == n && y == n)
	{
		count_num++;
		return;
	}
	else
	{
		int idx = map[x][y];
		bfs(map, x + idx, y);
		bfs(map, x, y + idx);
	}
}

long long dp(vector<vector<int>> &map)
{
	vector<vector<long long>> d(n + 1, vector<long long>(n + 1, 0));
	d[1][1] = 1;
	for(int i=1; i<=n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == n && j == n)
				break;
			int idx = map[i][j];
			if (i + idx <= n)
				d[i + idx][j] += d[i][j];
			if (j + idx <= n)
				d[i][j + idx] += d[i][j];
		}
	return d[n][n];
}

int main()
{
	cin >> n;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j<= n; j++)
			cin >> map[i][j];
	cout << dp(map) << '\n';
}