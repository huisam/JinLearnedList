#include<iostream>

typedef long long ll;

ll tree[2097152];
ll arr[1000001];

using namespace std;

ll init(int start, int node, int end) {
	if (start == end) {
		return tree[node] = arr[end];
	}
	else {
		return tree[node] = init(start, node << 1, (start + end) / 2) + init((start + end) / 2 + 1, (node << 1) + 1, end);
	}
}

ll sumTree(int node, int start, int end, int left, int right) {
	if (right < start || left > end)
		return 0;
	if (left <= start && right >= end)
		return tree[node];

	return sumTree(node * 2, start, (start + end) / 2, left, right) + sumTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

}

void update(int index, int node, int start, int end, ll diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end) {
		update(index, node * 2, start, (start + end) / 2, diff);
		update(index, node * 2 + 1, (start + end) / 2 + 1, end, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (register int i = 0; i < n; i++)
		cin >> arr[i];

	init(0, 1, n - 1);
	int cnt = m + k;
	while (cnt--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = (ll)c - arr[b - 1];
			arr[b - 1] = (ll)c;
			update(b-1, 1, 0, n - 1, diff);
		}
		else {
			cout << sumTree(1, 0, n - 1, b-1, c-1) << '\n';
		}
	}

	return 0;
}