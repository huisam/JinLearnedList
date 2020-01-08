#include<iostream>
#include<cstring>

using namespace std;

int d[501][501];
int n[501];
int sum[501];
int min(int a, int b) { return a < b ? a : b;}

int go(int now, int end) {
	if (end == now)
		return 0;
	if (end - now == 1)
		return d[now][end] = n[now] + n[end];
	if (d[now][end] != 0x3f3f3f3f)
		return d[now][end]; // dp 값 있으면 리턴
	else{
		for (int mid = now; mid < end; ++mid) {
			int left = go(now, mid);
			int right = go(mid + 1, end);
			d[now][end] = min(d[now][end], left + right);
		}
		return d[now][end] += sum[end] - sum[now - 1];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	int t1;
	cin >> t1;
	for (int t = 1; t <= t1; t++) {
		int k;
		cin >> k;
		memset(d, 0x3f, sizeof(d));
		for (int i = 1; i <= k; i++) {
			cin >> n[i];
			sum[i] = n[i] + sum[i - 1];
		}

		cout << go(1, k) << '\n';
	}
}