#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> edge(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> edge[i][j];
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (edge[i][k] != 0 && edge[k][j] != 0)
					edge[i][j] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << edge[i][j] << ' ';
		cout << '\n';
	}
}