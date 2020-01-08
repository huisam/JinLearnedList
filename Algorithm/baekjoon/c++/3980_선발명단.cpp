#include<iostream>
#include<vector>
using namespace std;

const int n = 11;
int ans;
vector<vector<int>> player;
vector<bool> check;

void go(int idx, int stat) {
	if (idx == n) {
		ans = (ans < stat) ? stat : ans;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!check[i] && player[i][idx] != 0) {
			check[i] = true;
			go(idx + 1, stat + player[i][idx]);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++){
		player.resize(n);
		check.resize(n);
		ans = 0;
		for (int i = 0; i < n; i++) {
			player[i].resize(n);
			for (int j = 0; j < n; j++)
				cin >> player[i][j];
		}
		go(0,0);
		cout << ans << '\n';
	}

}