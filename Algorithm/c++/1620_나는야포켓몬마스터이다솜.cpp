#include<iostream>

#define MAX_TABLE 200007
#define MAX_N 100000
#define MAX_LENGTH 21

struct PoketMon {
	char name[MAX_LENGTH];
	int num;
	PoketMon *prev;
	PoketMon *next;
};

char poketMonName[MAX_N][MAX_LENGTH];
PoketMon hashTable[MAX_TABLE];
PoketMon pdata[MAX_N];
char name[20];
char ans[20];

int pCnt;

using namespace std;

unsigned long myhash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

void mstrcpy(char *dst, const char *src) {
	int pos = 0;
	while (dst[pos] = src[pos]) {
		pos++;
	}
}

int mstrcmp(const char *str, const char *str2) {
	int pos = 0;
	while (str[pos]) {
		if (str[pos] != str2[pos])
			break;
		pos++;
	}
	return str[pos] - str2[pos];
}

int matoi(const char *str) {
	int ret = 0;
	while (*str) {
		ret = ret * 10 + *str - '0';
		str += 1;
	}
	return ret;
}

PoketMon* newNode() {
	PoketMon *node = &pdata[pCnt++];
	return node;
}

bool isNumber(const char *str) {
	int pos = 0;
	while (str[pos]) {
		if (str[pos] - '0' > 9 || str[pos] - '0' < 0)
			return false;
		pos++;
	}
	return true;
}

void addHashTable(const int num, const char *name) {
	PoketMon *node = newNode();
	mstrcpy(node->name, name);
	node->num = num;

	int key = myhash(name);

	PoketMon *head = hashTable[key].next;

	node->next = head;
	node->prev = &hashTable[key];

	if (head != 0) head->prev = node;
	hashTable[key].next = node;
}

int findHashTable(const char *name) {
	int key = myhash(name);

	PoketMon *node = hashTable[key].next;
	
	while (node) {
		PoketMon *next = node->next;
		if (!mstrcmp(node->name, name)) {
			return node->num;
		}
		node = next;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		mstrcpy(poketMonName[i], name);
		addHashTable(i, name);
	}

	for (int i = 1; i <= m; i++) {
		cin >> name;
		if (isNumber(name)) {
			int num = matoi(name);
			cout << poketMonName[num] << '\n';
		}
		else {
			cout << findHashTable(name) << '\n';
		}
	}
}