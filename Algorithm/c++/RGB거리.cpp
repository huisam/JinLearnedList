#include<iostream>
#include<vector>
using namespace std;

long long a[1001][3];

int min(int num1, int num2) { return num1 < num2 ? num1 : num2; }

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> d(n+1, vector<int>(3));
	for (int i = 1; i <= n; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	}
	a[1][0] = d[1][0];
	a[1][1] = d[1][1];
	a[1][2] = d[1][2];

	for (int i = 2; i <= n; i++) {
		a[i][0] = min(a[i - 1][1], a[i - 1][2]) + d[i][0];
		a[i][1] = min(a[i - 1][0], a[i - 1][2]) + d[i][1];
		a[i][2] = min(a[i - 1][0], a[i - 1][1]) + d[i][2];
	}
	cout << min(a[n][0], min(a[n][1], a[n][2])) << '\n';

}