#include<iostream>
#include<vector>
using namespace std;

int n, ans;
int m = 5;
int max(int a, int b) { return a > b ? a : b; }
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void dfs(vector<vector<int>> m, int cnt, int now) {
	if (cnt == 5) {
		ans = max(ans, now);
		return;
	}
	else {
		//위
		vector<vector<int>> t = m;
		int val = 0;
		for(int a = 0; a < n; a++)
			for (int i = 0; i < n - 1; i++) {
				if (t[i][a] != 0){
					for (int j = i + 1; j < n; j++) {
						if (t[j][a] == 0)
							continue;
						if (t[i][a] == t[j][a]) {
							t[i][a] *= 2;
							t[j][a] = 0;
							break;
						}
						else
							break;
					}
				}
			}
		for (int a = 0; a < n; a++)
			for (int i = 0; i < n - 1; i++) {
				if(t[i][a] == 0)
					for (int j = i + 1; j < n; j++) {
						if (t[j][a] != 0) {
							swap(t[i][a], t[j][a]);
							break;
						}
					}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				val = max(val, t[i][j]);
		dfs(t, cnt + 1, val);
		// 아래
		t = m;
		val = 0;
		for (int a = 0; a < n; a++)
			for (int i = n-1; i > 0; i--) {
				if (t[i][a] != 0) {
					for (int j = i - 1; j >= 0; j--) {
						if (t[j][a] == 0)
							continue;
						if (t[i][a] == t[j][a]) {
							t[i][a] *= 2;
							t[j][a] = 0;
							break;
						}
						else
							break;
					}
				}
			}
		for (int a = 0; a < n; a++)
			for (int i = n - 1; i > 0; i--) {
				if (t[i][a] == 0)
					for (int j = i - 1; j >= 0; j--) {
						if (t[j][a] != 0) {
							swap(t[i][a], t[j][a]);
							break;
						}
					}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				val = max(val, t[i][j]);
		dfs(t, cnt + 1, val);
		// 왼쪽
		t = m;
		val = 0;
		for (int a = 0; a < n; a++)
			for (int i = n - 1; i > 0; i--) {
				if (t[a][i] != 0) {
					for (int j = i - 1; j >= 0; j--) {
						if (t[a][j] == 0)
							continue;
						if (t[a][i] == t[a][j]) {
							t[a][i] *= 2;
							t[a][j] = 0;
							break;
						}
						else
							break;
					}
				}
			}
		for (int a = 0; a < n; a++)
			for (int i = n - 1; i > 0; i--) {
				if (t[a][i] == 0)
					for (int j = i - 1; j >= 0; j--) {
						if (t[a][j] != 0) {
							swap(t[a][i], t[a][j]);
							break;
						}
					}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				val = max(val, t[i][j]);
		dfs(t, cnt + 1, val);
		// 오른쪽	
		t = m;
		val = 0;
		for (int a = 0; a < n; a++)
			for (int i = 0; i < n - 1; i++) {
				if (t[a][i] != 0) {
					for (int j = i + 1; j < n; j++) {
						if (t[a][j] == 0)
							continue;
						if (t[a][i] == t[a][j]) {
							t[a][i] *= 2;
							t[a][j] = 0;
							break;
						}
						else
							break;
					}
				}
			}
		for (int a = 0; a < n; a++)
			for (int i = 0; i < n - 1; i++) {
				if (t[a][i] == 0)
					for (int j = i + 1; j < n; j++) {
						if (t[a][j] != 0) {
							swap(t[a][i], t[a][j]);
							break;
						}
					}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				val = max(val, t[i][j]);
		dfs(t, cnt + 1, val);


	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];
	
	dfs(m, 0, 0);
	cout << ans << '\n';
}