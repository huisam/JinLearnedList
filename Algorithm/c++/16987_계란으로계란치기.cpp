#include<iostream>
#include<vector>

using namespace std;
int n,ans;
vector<bool> check;
vector<pair<int, int>> egg;

int max(int a, int b) { return a < b ? b : a; }

void go(int idx, int cnt) {
	if (idx == n) {
		ans = max(ans, cnt);
		return;
	}
	if (check[idx])
		go(idx + 1, cnt);
	else {
		for (int i = 0; i < n; i++){
			if (!check[i] && idx != i) {
				int ncnt = cnt;
				egg[idx].first -= egg[i].second;
				egg[i].first -= egg[idx].second;
				if (egg[idx].first <= 0) {
					check[idx] = true;
					ncnt++;
				}
				if (egg[i].first <= 0) {
					check[i] = true;
					ncnt++;
				}
				go(idx + 1, ncnt);
				egg[idx].first += egg[i].second;
				egg[i].first += egg[idx].second;
				check[idx] = false;
				check[i] = false;
			}
		}
		ans = max(ans, cnt);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	egg.resize(n);
	check.resize(n);
	for (int i = 0; i < n; i++){	
		int s, w;
		cin >> s >> w;
		egg[i].first = s;
		egg[i].second = w;
	}
	
	go(0, 0);

	cout << ans << '\n';
	return 0;
}