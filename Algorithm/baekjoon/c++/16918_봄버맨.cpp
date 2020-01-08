#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;
int r, c, n;
queue<pair<int, int>> q;
vector<vector<int>> bo;
vector<string> map;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bomb() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == '.') {
				map[i][j] = 'O';
				bo[i][j] = 0;
			}
}

void action() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (bo[i][j] == 1) {
				q.push({ i,j });
				bo[i][j] = -3;
			}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		map[x][y] = '.';
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx == r || ny < 0 || ny == c)
				continue;
			map[nx][ny] = '.';
			bo[nx][ny] = -3;
		}
	}
}

void go() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == 'O')
				bo[i][j]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> n;
	map.resize(r);
	bo.resize(r);
	for (int i = 0; i < r; i++)
		cin >> map[i];

	for (int i = 0; i < r; i++) {
		bo[i].resize(c);
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'O')
				bo[i][j] = 0;
			else
				bo[i][j] = -3;
		}
	}

	if (n == 1) {
		for (int i = 0; i < r; i++)
			cout << map[i] << '\n';
	}
	else if (n % 2 == 0) {
		bomb();
		for (int i = 0; i < r; i++)
			cout << map[i] << '\n';
	}
	else {
		go();
		bomb();
		action();
		if (n % 4 == 1) {
			go();
			bomb();
			action();
		}
		for (int i = 0; i < r; i++)
			cout << map[i] << '\n';
	}
	return 0;
}