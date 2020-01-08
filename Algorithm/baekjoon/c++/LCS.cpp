#include<iostream>
#include<string>
using namespace std;

int d[1001][1001];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	ios_base::sync_with_stdio(false);
	string a;
	string b;

	cin >> a >> b;

	int n = a.size();
	int m = b.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j])
				d[i+1][j+1] = d[i][j] + 1;
			else
				d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
		}
	}
	cout << d[n][m] << '\n';

}