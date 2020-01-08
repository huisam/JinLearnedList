#include<iostream>

using namespace std;

struct Heap {
	int heap[100001];
	int heapIndex[100001];
	int index[100001];
	int heapSize;


	bool cmp(int a, int b) {
		if (heap[a] == heap[b]) return heapIndex[a] < heapIndex[b];
		else return heap[a] < heap[b];
	}

	void mswap(int a, int b) {
		int temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;

		temp = heapIndex[a];
		heapIndex[a] = heapIndex[b];
		heapIndex[b] = temp;

		index[heapIndex[a]] = a;
		index[heapIndex[b]] = b;
	}

	void update(int i) {
		while (i > 1 && cmp(i, i >> 1)) {
			mswap(i, i >> 1);
			i = i >> 1;
		}
	}

	void downdate(int i) {
		while (i * 2 <= heapSize) {
			int left = i << 1;
			if (cmp(left + 1, left))
				left++;

			if (cmp(i, left))
				break;

			mswap(i, left);
			i = left;
		}
	}

	void addHeapNode(int val, int i) {
		heap[++heapSize] = val;
		heapIndex[heapSize] = i;
		index[i] = heapSize;

		update(heapSize);
	}

	int popHeapNode() {
		int val = heap[1];
		heap[1] = heap[heapSize];
		heapIndex[1] = heapIndex[heapSize];
		index[1] = index[heapSize--];

		downdate(1);
		return val;
	}

	void updateHeapNode(int val, int i) {
		heap[index[i]] = val;
		update(index[i]);
		downdate(index[i]);
	}
};

Heap heaps;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (register int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		heaps.addHeapNode(num, i);
	}

	int m;
	cin >> m;
	while (m--) {
		int query;
		cin >> query;

		if (query == 2) {
			cout << heaps.heapIndex[1] << '\n';
		}
		else {
			int i, val;
			cin >> i >> val;
			heaps.updateHeapNode(val, i);
		}
	}

}