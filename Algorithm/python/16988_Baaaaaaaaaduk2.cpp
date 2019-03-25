#include<vector>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m, ans;
vector<vector<int>> map;
vector<vector<bool>> check;
int dx[] = {1,-1, 0,0};
int dy[] = {0,0,1,-1};

void set() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			check[i][j] = false;
}

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	int cnt = 1;
	bool find = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || map[nx][ny] == 1)
				continue;
			if (map[nx][ny] == 0) {
				find = false;
			}
			else if(map[nx][ny] == 2){
				check[nx][ny] = true;
				cnt++;
				q.push({ nx,ny });
			}
		}
	}
	if (!find) cnt = 0;
	return cnt;

}

void go(int x, int y, int idx) {

	if (idx == 1) {
		for (int i = x; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 0) {
					map[i][j] = 1;
					go( i, j, 2);
					set();
					map[i][j] = 0;
				}
	}
	else {
		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (map[i][j] == 2 && !check[i][j]) {
					check[i][j] = true;
					result += bfs(i, j);
				}
		}
		ans = max(result, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map.resize(n);
	check.resize(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		check[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (map[i][j] == 0) {
				map[i][j] = 1;
				go(i, j, 1);
				map[i][j] = 0;
			}
		}
	cout << ans << '\n';

	return 0;
}