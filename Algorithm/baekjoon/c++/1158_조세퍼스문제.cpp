#include<iostream>

using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *prev;
};

Node *node;
Node *head;
int cnt;

void add(int val) {
	
	if (node == 0) {
		node = new Node();
		node->val = val;
		head = node;
		return;
	}

	Node *newNode = new Node();
	newNode->val = val;
	newNode->prev = node;
	newNode->next = head;
	
	node->next = newNode;
	head->prev = newNode;

	node = newNode;
	cnt++;
}

int deleteNode(int nextCount) {
	for (register int i = 1; i < nextCount; i++)
		node = node->next;

	int ret = node->val;

	Node *prevNode = node->prev;
	Node *nextNode = node->next;

	nextNode->prev = node->prev;
	prevNode->next = node->next;

	node = node->next;
	cnt--;

	return ret;
}

int ans[5000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (register int i = 1; i <= n; i++)
		add(i);

	node = head;
	cout << "<";
	while (cnt) {
		cout << deleteNode(k) << ", ";
	}
	cout << node->val << ">\n";

	return 0;
}