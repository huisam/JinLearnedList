#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
struct dice {
	int u = 0;
	int d = 0;
	int l = 0;
	int r = 0;
	int f = 0;
	int b = 0;
	void right() {
		int temp = d;
		d = r;
		r = u;
		u = l;
		l = temp;
	}
	void left() {
		int temp = u;
		u = r;
		r = d;
		d = l;
		l = temp;
	}
	void down() {
		int temp = d;
		d = f;
		f = u;
		u = b;
		b = temp;
	}
	void up() {
		int temp = d;
		d = b;
		b = u;
		u = f;
		f = temp;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, k;
	cin >> n >> m >> x >> y >> k;
	vector<vector<int>> map(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	dice d;
	int dy, dx;
	while (k--) {
		int r;
		cin >> r;
		switch (r){
		case 1:
			dy = y + 1;
			if (dy >= m)
				break;
			y = dy;
			d.right();
			cout << d.u << '\n';
			if (map[x][y] != 0) {
				d.d = map[x][y];
				map[x][y] = 0;
			}
			else
				map[x][y] = d.d;
			break;
		case 2:
			dy = y - 1;
			if (dy < 0)
				break;
			y = dy;
			d.left();
			cout << d.u << '\n';
			if (map[x][y] != 0) {
				d.d = map[x][y];
				map[x][y] = 0;
			}
			else
				map[x][y] = d.d;
			break;
		case 3:
			dx = x - 1;
			if (dx < 0)
				break;
			x = dx;
			d.up();
			cout << d.u << '\n';
			if (map[x][y] != 0) {
				d.d = map[x][y];
				map[x][y] = 0;
			}
			else
				map[x][y] = d.d;
			break;
		case 4:
			dx = x + 1;
			if (dx >= n)
				break;
			x = dx;
			d.down();
			cout << d.u << '\n';
			if (map[x][y] != 0) {
				d.d = map[x][y];
				map[x][y] = 0;
			}
			else
				map[x][y] = d.d;
			break;
		}
	}

}