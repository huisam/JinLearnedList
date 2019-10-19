#include<iostream>

#define MAX_TABLE 200007
#define MAX_DATA 100001
#define MAX_NAME 21

using namespace std;

void mstrcpy(char *dst, const char *src) {
	int pos = 0;
	while (src[pos]) {
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
}

int mstrcmp(const char *str1, const char *str2) {
	int pos = 0;
	while (str1[pos]) {
		if (str1[pos] != str2[pos])
			break;
		pos++;
	}
	return str1[pos] - str2[pos];
}

int matoi(const char *str) {
	int ret = 0;
	while (*str) {
		ret = ret * 10 + *str - '0';
		str += 1;
	}
	return ret;
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


struct Poketmon {
	char name[MAX_NAME];
	int num;
};

struct Node {
	Poketmon *poketmon;
};


Poketmon poketmons[MAX_DATA];
Node hashTable[MAX_TABLE];
int pCnt = 1;
char name[MAX_NAME];

Poketmon *newMonster(const char *name, int num) {
	Poketmon *node = &poketmons[pCnt++];
	mstrcpy(node->name, name);
	node->num = num;
	return node;
}

void addHashTable(Poketmon *poketmon) {
	int key = myhash(poketmon->name);

	Node *node = &hashTable[key];

	while (node->poketmon != 0) {
		key = (key + 1) % MAX_TABLE;
		node = &hashTable[key];
	}
	node->poketmon = poketmon;
}

int findHashTable(const char *name) {
	int key = myhash(name);

	Node *node = &hashTable[key];

	while (mstrcmp(node->poketmon->name, name) != 0) {
		key = (key + 1) % MAX_TABLE;
		node = &hashTable[key];
	}

	return node->poketmon->num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;


	for (register int i = 1; i <= n; i++) {
		cin >> name;
		Poketmon *node = newMonster(name, i);
		addHashTable(node);
	}

	while (m--) {
		cin >> name;
		if (isNumber(name)) {
			int num = matoi(name);
			cout << poketmons[num].name << '\n';
		}
		else
			cout << findHashTable(name) << '\n';
	}

}