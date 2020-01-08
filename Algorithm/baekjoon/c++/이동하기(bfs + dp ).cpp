#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
vector<int> set_candy;
// recursion BFS
void check_recursion(vector<vector<int>> &map, int x, int y, int candy)
{
	if (x > n || y > m)
		return;
	else if (x == n && y == m) {
		candy += map[x][y];
		set_candy.push_back(candy);
		return;
	}
	candy += map[x][y];
	check_recursion(map, x + 1, y, candy);
	check_recursion(map, x, y + 1, candy);
	check_recursion(map, x + 1, y + 1, candy);

}
// queue BFS
void check_queue(vector<vector<int>> &map)
{
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(1, 1)));
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int candy = q.front().first;
		q.pop();
		if (x > n || y > m)
			continue;
		else if (x == n && y == m)
		{
			candy += map[x][y];
			set_candy.push_back(candy);
		}
		else {
			candy += map[x][y];
			q.push(make_pair(candy, make_pair(x + 1, y)));
			q.push(make_pair(candy, make_pair(x , y + 1)));
			q.push(make_pair(candy, make_pair(x + 1, y + 1)));
		}
	}
}

// dp
int check_dp(vector<vector<int>> &map)
{
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = max(d[i - 1][j - 1], max(d[i - 1][j], d[i][j - 1])) + map[i][j];

	return d[n][m];
}

int main()
{

	cin >> n >> m;
	vector<vector<int>> map(n+1, vector<int>(m+1, 0));
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < m+1; j++)
			cin >> map[i][j];
	cout << check_dp(map) << '\n';
	//check_queue(map);
	//cout << *max_element(set_candy.begin(), set_candy.end()) << '\n';
}