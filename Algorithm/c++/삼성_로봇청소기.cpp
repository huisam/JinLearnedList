#include<queue>
#include<cstdio>

using namespace std;
int map[50][50];
bool check[50][50];
int n, m;

struct robot {
	int x;
	int y;
	int r;
	int same = 0;
	robot(int _x, int _y, int _r) :x(_x), y(_y), r(_r) {}
};

int main() {
	scanf("%d %d", &n, &m);
	int x, y, r;
	scanf("%d %d %d", &y, &x, &r);
	robot first(x, y, r);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	int cnt = 0;
	queue<robot> q;
	q.push(first);
	while (!q.empty()) {
		robot now = q.front();
		q.pop();
		
		if (!check[now.y][now.x]) {
			check[now.y][now.x] = true;
			cnt++;
		}

		if (now.same == 4) {
			if (now.r == 0) {
				if (map[now.y + 1][now.x] == 0)
				{
					now.y += 1;
					now.same = 0;
					q.push(now);
				}
			}
			else if (now.r == 1) {
				if (map[now.y][now.x - 1] == 0) {
					now.x -= 1;
					now.same = 0;
					q.push(now);
				}
			}
			else if (now.r == 2) {
				if (map[now.y - 1][now.x] == 0) {
					now.y -= 1;
					now.same = 0;
					q.push(now);
				}
			}
			else if (now.r == 3) {
				if (map[now.y][now.x + 1] == 0) {
					now.x += 1;
					now.same = 0;
					q.push(now);
				}
			}
		}
		else {
			if (now.r == 0) {
				if (!check[now.y][now.x - 1] && map[now.y][now.x-1] == 0) {
					now.same = 0;
					now.x -= 1;
				}
				else
					now.same++;

				now.r = 3;
				q.push(now);
			}
			else if (now.r == 1) {
				if (!check[now.y-1][now.x] && map[now.y - 1][now.x] == 0) {
					now.same = 0;
					now.y -= 1;
				}
				else
					now.same++;
				now.r = 0;
				q.push(now);
			}
			else if (now.r == 2) {
				if (!check[now.y][now.x+1] && map[now.y][now.x + 1] == 0) {
					now.same = 0;
					now.x += 1;
				}
				else
					now.same++;
				now.r = 1;
				q.push(now);
			}
			else if (now.r == 3) {
				if (!check[now.y + 1][now.x] && map[now.y + 1][now.x] == 0) {
					now.same = 0;
					now.y += 1;
				}
				else
					now.same++;
				now.r = 2;
				q.push(now);
			}
		}
		
	}
	printf("%d\n", cnt);
}