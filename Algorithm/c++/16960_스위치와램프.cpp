#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> check(m + 1);
	vector<vector<int>> go(n);
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			go[i].push_back(x);
			check[x]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < go[i].size(); j++)
			check[go[i][j]]--;
		bool find = false;
		for (int i = 1; i <= m; i++) {
			if (check[i] <= 0) {
				find = true;
				break;
			}
		}
		if (!find) {
			cout << 1 << '\n';
			return 0;
		}
		for (int j = 0; j < go[i].size(); j++)
			check[go[i][j]]++;
	}
	cout << 0 << '\n';
	return 0;
}