#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, h;
int dx[] = { 1,-1,0, 0, 1,-1,1,-1 };
int dy[] = { 0, 0,1,-1,-1, 1,1,-1 };
void dfs(vector<vector<int>>&map, vector<vector<bool>>&check, int x, int y) {
	if (check[x][y] || map[x][y] == 0)
		return;
	check[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= h || ny < 0 || ny >= n)
			continue;
		dfs(map, check, nx, ny);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> h;
	while (n != 0 || h != 0) {
		vector<vector<int>> map(h, vector<int>(n, 0));
		vector<vector<bool>> check(h, vector<bool>(n, false));
		for (int i = 0; i < h; i++){
			for (int j = 0; j < n; j++){
				cin >> map[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j] && map[i][j] == 1) {
					dfs(map, check, i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
		cin >> n >> h;
	}

}