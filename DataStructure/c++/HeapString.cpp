#include<iostream>

using namespace std;

int mstrcmp(const char *str1, const char *str2) {
	int pos = 0;
	while (str1[pos]) {
		if (str1[pos] != str2[pos])
			break;
		pos++;
	}
	return str1[pos] - str2[pos];
}

void mstrcpy(char *dst, const char *src) {
	int pos = 0;
	while (src[pos]) {
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
}

struct Node {
	char name[20];

	bool operator<(const Node node) {
		return mstrcmp(name, node.name) < 0;
	}

	bool operator<=(const Node node) {
		return mstrcmp(name, node.name) <= 0;
	}
};

Node pool[10000];
int nCnt;

Node *newNode(const char *name) {
	Node *node = &pool[nCnt++];
	mstrcpy(node->name, name);
	return node;
}

struct Heap {
	Node *heap[100];
	int heapSize;

	void mswap(int a, int b) {
		Node *temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;
	}

	void addHeap(Node *node) {
		heap[++heapSize] = node;
		int i = heapSize;

		while (i > 1 && *heap[i] < *heap[i >> 1]) {
			mswap(i, i >> 1);
			i = i >> 1;
		}
	}

	Node *popHeap() {
		Node *ret = heap[1];
		heap[1] = heap[heapSize--];

		int i = 1;

		while (i * 2 <= heapSize) {
			int left = i << 1;
			if (*heap[left + 1] < *heap[left])
				left++;
			if (*heap[i] <= *heap[left])
				break;

			mswap(i, left);
			i = left;
		}
		return ret;
	}
};

Heap heap;

int main() {
	heap.addHeap(newNode("abc"));
	heap.addHeap(newNode("ddd"));
	heap.addHeap(newNode("zed"));
	heap.addHeap(newNode("aa"));

	while (heap.heapSize) {
		cout << heap.popHeap()->name << '\n';
	}
}