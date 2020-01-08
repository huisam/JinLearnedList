#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int ans = 987654321;

void go(vector<vector<int>> &d, vector<bool> &c, int cnt, int idx) {
	if (cnt == n / 2) {
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < n; i++){
			if (c[i])
				start.push_back(i);
			else
				link.push_back(i);
		}
		int score1 = 0;
		int score2 = 0;

		for (int i = 0; i < cnt; i++)
			for (int j = i + 1; j < cnt; j++) {
				score1 += d[start[i]][start[j]] + d[start[j]][start[i]];
				score2 += d[link[i]][link[j]] + d[link[j]][link[i]];
			}
		ans = min(ans, abs(score1 - score2));
	}
	if (idx == n)
		return;
	else {
		for (int i = idx; i < n; i++){
			if (!c[i]) {
				c[i] = true;
				go(d, c, cnt + 1, i + 1);
				c[i] = false;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<vector<int>> d(n, vector<int>(n));
	vector<bool> c(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];

	c[0] = true;
	go(d, c, 1, 1);
	cout << ans << '\n';
	return 0;
}