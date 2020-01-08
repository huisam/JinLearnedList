#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,ans;

bool pred(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	else return a.first < b.first;
}

void go(vector<pair<int, int>> &num, int idx, int health, int happy) {
	if (idx == n) {
		ans = max(ans, happy);
		return;
	}
	if (health - num[idx].first <= 0) {
		ans = max(ans, happy);
		return;
	}
	else {
		go(num, idx + 1, health - num[idx].first, happy + num[idx].second);
		go(num, idx + 1, health, happy);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int, int>> num(n);
	for (int i = 0; i < n; i++){
		int now;
		cin >> now;
		num[i].first = now;
	}
	for (int i = 0; i < n; i++){
		int now;
		cin >> now;
		num[i].second = now;
	}
	sort(num.begin(), num.end(), pred);
	go(num, 0, 100, 0);
	cout << ans << '\n';
}