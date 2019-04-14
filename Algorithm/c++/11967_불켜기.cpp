#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
	int x;
	int y;
	int r;
	node() {};
	node(int _x, int _y, int _r) :x(_x), y(_y), r(_r) {};
};

int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> n >> m;
	vector<vector<vector<node>>> list(n + 1, vector<vector<node>>(n + 1));
	while (m--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		list[x][y].push_back({ a,b,0 });
	}
	int ans = 1;
	vector<vector<bool>> check(n + 1, vector<bool>(n + 1));
	vector<vector<bool>> on(n + 1, vector<bool>(n + 1));
	queue<node> q;
	q.push({ 1,1,1 });
	check[1][1] = true;
	on[1][1] = true;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.r == n * n)
			break;

		if (!list[now.x][now.y].empty()) {
			for (auto val : list[now.x][now.y]) {
				if (!on[val.x][val.y]) {
					ans++;
					on[val.x][val.y] = true;
				}
			}
			list[now.x][now.y].clear();
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n || !on[nx][ny])
				continue;
			if (!check[nx][ny]) {
				check[nx][ny] = true;
				q.push({ nx,ny,now.r+1 });
			}
		}
		q.push({ now.x,now.y,now.r + 1 });
	}
	cout << ans << '\n';
	return 0;
}