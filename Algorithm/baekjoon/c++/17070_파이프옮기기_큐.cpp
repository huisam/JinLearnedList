#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/* 실행시간 : 96ms */
struct pipe {
	int x;
	int y;
	int r; // 가로 0 세로 1 대각선 2
	pipe() {};
	pipe(int _x, int _y, int _r) :x(_x), y(_y), r(_r) {};
};
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	queue<pipe> q;
	q.push({ 0,1,0 }); // 초기값
	while (!q.empty()) {
		pipe now = q.front();
		q.pop();

		if (now.x == n - 1 && now.y == n - 1) { // 종료조건
			ans++;
			continue;
		}
		for (int i = 0; i < 3; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (i == 0 && now.r == 1) // 가로는 세로 못가
				continue;
			if (i == 1 && now.r == 0) // 세로는 가로 못가
				continue;
			if (nx >= n || ny >= n || map[nx][ny] == 1) // 벽도 못가
				continue;
			if (i == 2 && (map[nx - 1][ny] == 1 || map[nx][ny - 1] == 1)) // 대각선 조건
				continue;
			q.push({ nx,ny,i });
		}
	}
	cout << ans << '\n';
}