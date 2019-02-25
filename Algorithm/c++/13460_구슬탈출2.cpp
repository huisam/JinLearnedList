#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n, m;

struct boll {
	int x;
	int y;
	int cnt = 0;
	boll() {};
	boll(int _x, int _y) :x(_x), y(_y) {};
	boll(int _x, int _y, int _cnt) :x(_x), y(_y), cnt(_cnt) {};
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<string> map(n);
	boll red, blue, end;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R')
				red = boll(i, j);
			if (map[i][j] == 'B')
				blue = boll(i, j);
			if (map[i][j] == 'O')
				end = boll(i, j);
		}
	bool find = false;
	int ans = -1;
	queue<pair<boll, boll>> q;
	q.push({ red, blue });
	while (!q.empty()) {
		boll redNow = q.front().first;
		boll blueNow = q.front().second;
		q.pop();
		bool find = false;
		if (redNow.cnt == 10)
			break;
		else {
			// 끝지점으로 갈 수 잇니? 레드와 블루가 동시에 가면 안되는데
			for (int i = 0; i < 4; i++) {
				bool red_end = false;
				bool blue_end = false;

				int nx = redNow.x + dx[i];
				int ny = redNow.y + dy[i];
				while (map[nx][ny] != '#') {
					if (map[nx][ny] == 'O')
						red_end = true;
					nx += dx[i];
					ny += dy[i];
				}
				int rx = nx - dx[i];
				int ry = ny - dy[i];

				nx = blueNow.x + dx[i];
				ny = blueNow.y + dy[i];
				while (map[nx][ny] != '#') {
					if (map[nx][ny] == 'O')
						blue_end = true;
					nx += dx[i];
					ny += dy[i];
				}
				int bx = nx - dx[i];
				int by = ny - dy[i];

				if (rx == bx && ry == by) {
					switch (i){
						case 0:
							if (redNow.y > blueNow.y)
								by -= dy[i];
							else
								ry -= dy[i];
							break;
						case 1:
							if (redNow.y > blueNow.y)
								ry -= dy[i];
							else
								by -= dy[i];
							break;
						case 2:
							if (redNow.x > blueNow.x)
								bx -= dx[i];
							else
								rx -= dx[i];
							break;
						case 3:
							if (redNow.x > blueNow.x)
								rx -= dx[i];
							else
								bx -= dx[i];
							break;
					}
				}

				if (red_end && !blue_end) {
					ans = redNow.cnt + 1;
					find = true;
				}
				else if (blue_end)
					continue;
				else if (rx == redNow.x && ry == redNow.y && bx == blueNow.x && by == blueNow.y)
					continue;
				else {
					q.push({ boll(rx,ry,redNow.cnt + 1), boll(bx,by,blueNow.cnt + 1) });
				}
			}
			// 안되면 이동하고 큐에 넣어
			// 되면 끝!답
		}
		if (find)
			break;
	}
	cout << ans << '\n';
}