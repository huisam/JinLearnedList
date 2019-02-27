#include<iostream>
#include<vector>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dx2[4][3] = { {0,0,-1}, {-1,1,0}, {0,0,1}, {-1,1,0} };
int dy2[4][3] = { {1,-1,0}, {0,0,1}, {-1,1,0}, {0,0,-1} };
vector<vector<bool>> visit;
vector<vector<int>> map;
int n, m, ans;
int max(int a, int b) { return a > b ? a : b; }

void dfs(int x, int y, int depth, int now) {
	if (depth == 4) {
		ans = max(ans, now);
		return;
	}
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (!visit[nx][ny])
			dfs(nx, ny, depth + 1, now + map[nx][ny]);
	}
	visit[x][y] = false;
}

void tt(int x, int y, int now) {
	for (int i = 0; i < 4; i++) {
		int val = now;
		bool find = true;
		for (int j = 0; j < 3; j++) {
			int nx = dx2[i][j] + x;
			int ny = dy2[i][j] + y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				find = false;
				break;
			}
			val += map[nx][ny];
		}
		if (find)
			ans = max(val, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map.resize(n);
	visit.resize(n);
	for (int i = 0; i < n; i++)
	{
		visit[i].resize(m, false);
		map[i].resize(m, 0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			dfs(i, j, 1, map[i][j]);
			tt(i, j, map[i][j]);
		}
	cout << ans << '\n';
}