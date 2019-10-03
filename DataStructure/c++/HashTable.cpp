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

#define MAX_TABLE 100007
#define MAX_DATA 50000

struct Table {
	char name[20];
	int id;
};

struct Node {
	Node *prev;
	Node *next;
	Table *table;
};

Node hashTable[MAX_TABLE];
Node arrNode[MAX_DATA];
Table arrTable[MAX_DATA];

int tCnt, nCnt;

Table *newTable() {
	Table *table = &arrTable[tCnt++];
	return table;
}

Node *newNode() {
	Node *node = &arrNode[nCnt++];
	node->prev = 0;
	node->next = 0;
	node->table = 0;
	return node;
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

void initMemory() {
	nCnt = 0, tCnt = 0;
	for (register int i = 0; i < MAX_TABLE; i++) {
		hashTable[i].next = 0;
		hashTable[i].prev = 0;
		hashTable[i].table = 0;
	}
}

void addHashTable(const char *str, const int id) {
	Table *table = newTable();
	table->id = id;
	mstrcpy(table->name, str);

	Node *node = newNode();
	node->table = table;

	int hashKey = myhash(str);

	Node *head = hashTable[hashKey].next;

	node->prev = &hashTable[hashKey];
	node->next = head;

	if (head != 0) head->prev = node;
	hashTable[hashKey].next = node;
}

int modifyHashTable(const char *str, const int fixID) {
	int hashKey = myhash(str);

	Node *node = hashTable[hashKey].next;
	while (node) {
		Node *next = node->next;
		if (!mstrcmp(str, node->table->name)) {
			node->table->id = fixID;
			return 1;
		}

		node = next;
	}
	return 0;
}

void deleteHashTable(const char *str) {
	int hashKey = myhash(str);

	Node *node = hashTable[hashKey].next;
	while (node) {
		Node *next = node->next;
		if (!mstrcmp(str, node->table->name)) {
			// deleteNode
			if (node->next != 0) node->next->prev = node->prev;
			if (node->prev != 0) node->prev->next = node->next;

		}

		node = next;
	}
}


int main() {
	addHashTable("gogo", 1);
	addHashTable("gogo", 2);
	addHashTable("abc", 10);

	modifyHashTable("abc", 4);

	deleteHashTable("gogo");

	return 0;
}