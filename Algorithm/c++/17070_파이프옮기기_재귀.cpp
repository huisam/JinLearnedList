#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct pipe {
	int x;
	int y;
	int r; // 가로 0 세로 1 대각선 2
	pipe() {};
	pipe(int _x, int _y, int _r) :x(_x), y(_y), r(_r) {};
};
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
int ans, n;
vector<vector<int>> map;

void go(int x, int y, int r) {
	if (x == n - 1 && y == n - 1) { // 종료 조건
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (i == 0 && r == 1) // 가로는 세로 못가
			continue;
		if (i == 1 && r == 0) // 세로는 가로 못가
			continue;
		if (nx >= n || ny >= n || map[nx][ny] == 1)
			continue;
		if (i == 2 && (map[nx - 1][ny] == 1 || map[nx][ny - 1] == 1)) // 대각선 조건
			continue;
		go(nx, ny, i); // 재귀호출
	}


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ans = 0;
	map.resize(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	go(0, 1, 0);
	
	cout << ans << '\n';
}