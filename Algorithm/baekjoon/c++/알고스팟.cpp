#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<bool>> check(100, vector<bool>(100, false));

int bfs(vector<string> &map, int count_num)
{
	deque<pair<int, pair<int, int>>> q;
	vector<int> solution;
	q.push_front(make_pair(0,make_pair(0, 0)));
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int score = q.front().first;
		q.pop_front();

		if (check[y][x])
			continue;

		if (x == n - 1 && y == m - 1)
		{
			solution.push_back(score);
			continue;
		}
		
		if (!check[y][x]) {
			check[y][x] = true;
			if (map[y][x] == '1')
				score++;
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
					continue;
				else if (map[next_y][next_x] == '1')
					q.push_back(make_pair(score, make_pair(x + dx[i], y + dy[i])));
				else if (map[next_y][next_x] == '0')
					q.push_front(make_pair(score, make_pair(x + dx[i], y + dy[i])));
			}
		}
	}
	return *min_element(solution.begin(), solution.end());
}
int main()
{

	cin >> n >> m;
	vector<string> map(m);
	for (auto &v : map)
		cin >> v;

	cout << bfs(map, 0) << '\n';

}