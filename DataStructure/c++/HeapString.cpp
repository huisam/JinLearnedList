#include<iostream>

using namespace std;

void mstrcpy(char *dst, const char *src) {
	int pos = 0;
	while (dst[pos] = src[pos]) {
		pos++;
	}
}

int mstrcmp(const char *str1, const char* str2) {
	int pos = 0;
	while (str1[pos]) {
		if (str1[pos] != str2[pos])
			break;
		pos++;
	}
	return str1[pos] - str2[pos];
}

#define MAX_SIZE 100000

struct Node {
	char data[20];
};

Node heap[MAX_SIZE];
int heapSize;
char copys[20];

void mswap(const int idx, const int idx2) {
	mstrcpy(heap[MAX_SIZE - 1].data, heap[idx].data);
	mstrcpy(heap[idx].data, heap[idx2].data);
	mstrcpy(heap[idx2].data, heap[MAX_SIZE - 1].data);
}

void addHeapNode(const char *str) {
	mstrcpy(heap[++heapSize].data, str);
	int i = heapSize;

	while (i > 1 && mstrcmp(heap[i / 2].data, heap[i].data) > 0) {
		mswap(i / 2, i);
		i /= 2;
	}
}

char *popHeapNode() {
	mstrcpy(copys, heap[1].data);
	mstrcpy(heap[1].data, heap[heapSize--].data);
	int i = 1;

	while (i * 2 <= heapSize) {
		int left = i * 2;

		if (mstrcmp(heap[left].data, heap[left + 1].data) > 0)
			left++;

		if (mstrcmp(heap[i].data, heap[left].data) <= 0)
			break;

		mswap(i, left);
		i = left;
	}

	return copys;
}

int main() {
	addHeapNode("gogo");
	addHeapNode("abc");
	addHeapNode("aaa");

	popHeapNode();
	popHeapNode();
	popHeapNode();

}