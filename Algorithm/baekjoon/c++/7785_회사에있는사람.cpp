#include<iostream>

#define MAX_LENGTH 6
#define MAX_NODE 1000000
#define MAX_TABLE (MAX_NODE >> 1) + 7

using namespace std;

unsigned long mhash(const char *str)
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
	while (src[pos]) {
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
}

int mstrcmp(const char *str1, const char *str2) {
	int pos = 0;
	while (str2[pos]) {
		if (str1[pos] != str2[pos])
			break;
		pos++;
	}
	return str1[pos] - str2[pos];
}

struct Node {
	char name[MAX_LENGTH];
	bool isIn;

	bool operator<(const Node &node) {
		return mstrcmp(name, node.name) > 0;
	}
};

Node nodePool[MAX_NODE];
Node *arr[MAX_NODE];
Node *temp[MAX_NODE];
int nCnt;

Node *newNode(const char *name) {
	Node *n = &nodePool[nCnt];
	mstrcpy(n->name, name);
	n->isIn = true;
	arr[nCnt] = &nodePool[nCnt];
	nCnt++;
	return n;
}

struct Table {
	Node *node;
	Table *prev;
	Table *next;
};

Table tablePool[MAX_NODE];
int tCnt;
Table hashTable[MAX_TABLE];

Table *newTable(Node *node) {
	Table* t = &tablePool[tCnt++];
	t->node = node;
	t->prev = 0;
	t->next = 0;
	return t;
}

void addHashTable(Node *node) {
	int key = mhash(node->name);

	Table *head = hashTable[key].next;

	Table *entity = newTable(node);

	entity->prev = &hashTable[key];
	entity->next = head;

	if (head != 0) head->prev = entity;
	hashTable[key].next = entity;
}

Node* findHashTable(const char *str) {
	int key = mhash(str);

	Table *head = hashTable[key].next;
	while (head) {
		if (mstrcmp(str, head->node->name) == 0)
			return head->node;
		head = head->next;
	}
	return 0;
}

void mergeSort(Node **arr, int len) {
	if (len < 2)
		return;
	int mid = len / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, len - mid);
	int i = 0, j = mid, k = 0;
	while (i < mid && j < len) {
		if (*arr[i] < *arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i < mid) {
		temp[k++] = arr[i++];
	}
	while (j < len) {
		temp[k++] = arr[j++];
	}
	for (register int a = 0; a < len; ++a)
		arr[a] = temp[a];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		char name[MAX_LENGTH];
		char status[MAX_LENGTH];
		cin >> name >> status;
		if (mstrcmp(status, "enter") == 0) {
			Node *node = findHashTable(name);
			if (node != 0)
				node->isIn = true;
			else
				addHashTable(newNode(name));
		}
		else {
			Node *node = findHashTable(name);
			if(node)
				node->isIn = false;
		}
	}

	mergeSort(arr, nCnt);
	for (register int i = 0; i < nCnt; ++i) {
		if (arr[i]->isIn)
			cout << arr[i]->name << '\n';
	}
}