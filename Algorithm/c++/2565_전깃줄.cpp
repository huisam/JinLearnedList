#include<iostream>

using namespace std;

int n;
int arr[501];
int temp[501];
int cnt;

int lowerBound(int left, int right, int val) {
	
	while (right > left) {
		int mid = (right + left) / 2;
		if (temp[mid] >= val)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (register int i = 0; i < n; i++) {
		int first, second;
		cin >> first >> second;
		arr[second - 1] = first;


	}

	for (register int i = 0; i < 501; i++) {
		if (arr[i] == 0)
			continue;

		if (cnt == 0 || temp[cnt - 1] < arr[i]) {
			temp[cnt++] = arr[i];
		}
		else {
			int idx = lowerBound(0, cnt - 1, arr[i]);
			temp[idx] = arr[i];
		}
	}


	cout << n - cnt << '\n';

	return 0;
}