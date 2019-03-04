#include<vector>
#include<queue>
#include<string>
#include<tuple>
#include<iostream>

using namespace std;

vector<string> map(8);
int dx[] = {0,0,0,1,1,1,-1,-1,-1};
int dy[] = { 1,-1,0,1,-1,0,1,-1,0 };
bool ans;
void change() {
	for (int i = 7; i >= 0; i--){
		if (i == 0)
			map[i] = "........";
		else
			map[i] = map[i - 1];
	}
}

void bfs() {
	queue<tuple<int, int, int>> q;
	vector<vector<bool>> check(8, vector<bool>(8, false));
	q.push({ 7,0,0 });
	int prv = 0;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int t = get<2>(q.front());
		q.pop();
		if (prv != t) {
			change();
			prv = t;
		}
		if (map[x][y] == '#')
			continue;
		for (int i = 0; i < 9; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || check[nx][ny])
				continue;
			if (map[nx][ny] == '#')
				continue;

			if (nx == 0 && ny == 7) {
				ans = true;
				return;
			}
			if (t >= 8) {
				check[nx][ny] = true;
			}
			q.push({ nx,ny, t + 1 });
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 8; i++)
		cin >> map[i];
	
	bfs();
	if (ans)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}