#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct node {
	int x, y, r, d;
	node(int _x, int _y, int _r, int _d) :x(_x), y(_y), r(_r), d(_d) {};
};

int main() {

	scanf("%d %d", &n, &m);
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> check(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	}
	int ans = -1;
	queue<node> q;
	q.push({ 0,0,1,1 });
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		bool find = false;
		for (int i = 0; i < 4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (now.r == 0 && (check[nx][ny] == 2 || check[nx][ny] == 1))
				continue;
			else if (now.r == 1 && check[nx][ny] == 1)
				continue;
			if (nx == n - 1 && ny == m - 1) {
				ans = now.d + 1;
				find = true;
				break;
			}

			if (now.r == 1)
				check[nx][ny] = 1;
			else
				check[nx][ny] = 2;

			if (now.r == 1 && map[nx][ny] == 1)
				q.push({ nx,ny,0,now.d + 1 });
			else if (map[nx][ny] == 0)
				q.push({nx, ny, now.r, now.d + 1});

		}
		if (find)
			break;
	}
	printf("%d\n", ans);
	return 0;
}