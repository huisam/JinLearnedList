#include<iostream>
#include<algorithm>

#define MAX_N 1000000

using namespace std;

int arr[MAX_N];


int binarySearch(int start, int end, int val) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] < val)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	for (register int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n;
		for (register int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n);
		int num;
		cin >> m;
		while (m--) {
			cin >> num;
			int idx = binarySearch(0, n - 1, num);
			int ans = (arr[idx] == num) ? 1 : 0;
			cout << ans << '\n';
		}
	}

}