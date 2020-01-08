#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> snake(101);
vector<int> ladder(101);
vector<int> visit(101);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (n--) {
		int now, next;
		cin >> now >> next;
		ladder[now] = next;
	}
	while (m--) {
		int now, next;
		cin >> now >> next;
		snake[now] = next;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visit[1] = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == 100) {
			cout << cnt << '\n';
			return 0;
		}

		for (int i = 1; i < 7; i++){
			int nx = now + i;
			if (nx > 100 || visit[nx] != 0)
				continue;
			visit[nx] = cnt + 1;
			if (snake[nx] != 0) {
				nx = snake[nx];
				visit[nx] = cnt + 1;
			}
			if (ladder[nx] != 0) {
				nx = ladder[nx];
				visit[nx] = cnt + 1;
			}
			q.push({ nx, cnt + 1 });
		}
	}
	return 0;
}