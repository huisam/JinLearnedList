#include<iostream>

void mstrcpy(char *dst, const char *src) {
	int pos = 0;
	while (src[pos]) {
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
}

using namespace std;

struct Node {
	char name[11];
};

Node nodePool[100000];
int nCnt;

Node *newNode(const char *name) {
	Node *n = &nodePool[nCnt++];
	mstrcpy(n->name, name);
	return n;
}

struct Entity {
	int cnt;
	Node *next;
};

Entity arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int u, n;
	cin >> u >> n;
	while (n--) {
		char name[11];
		int price;
		cin >> name >> price;
		if (arr[price].next == 0)
			arr[price].next = newNode(name);
		arr[price].cnt++;
	}

	int minidx = 987654321;
	for (register int i = 0; i <= u; ++i) {
		if (arr[i].cnt != 0) {
			if (minidx == 987654321)
				minidx = i;
			else if (arr[i].cnt < arr[minidx].cnt)
				minidx = i;
		}
	}
	cout << arr[minidx].next->name << ' ' << minidx << '\n';
}