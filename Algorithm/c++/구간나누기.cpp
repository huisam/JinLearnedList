
#include<iostream>

using namespace std;
int n, m;
int a[101];
int d[101][101];
bool c[101][101];
int min = -32768 * 101;

int go(int x, int y) {
	if (y == 0) 
		return 0;
	if (x <= 0) 
		return min;
	if (c[x][y]) 
		return d[x][y];
	c[x][y] = true;
	int &ans = d[x][y];
	ans = go(x - 1, y);
	int sum = 0;
	for (int k = x; k >= 1; k--) {
		sum += a[k];
		int temp = go(k - 2, y - 1) + sum;
		if (ans < temp) ans = temp;
	}
	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << go(n, m) << '\n';
}