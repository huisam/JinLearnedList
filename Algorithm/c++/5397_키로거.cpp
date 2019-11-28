#include<iostream>
#include<string>

using namespace std;

struct Node {
	char val;
	Node *prev;
	Node *next;
};

Node pool[1000001];
int nCnt;

Node* newNode(char val) {
	Node *n = &pool[nCnt++];
	n->val = val;
	n->next = 0;
	n->prev = 0;
	return n;
}

struct List {
	Node *cursor;
	Node *head;

	void push(Node *node) {
		if (head == 0) {
			head = node;
			cursor = node;
		}
		else if (cursor == 0) {
			head->prev = node;
			node->next = head;

			head = head->prev;
			cursor = node;
		}
		else {
			node->prev = cursor;
			node->next = cursor->next;

			if (cursor->next != 0) cursor->next->prev = node;
			cursor->next = node;

			cursor = node;
		}
	}

	void shiftLeft() {
		if (cursor != 0)
			cursor = cursor->prev;
	}

	void shiftRight() {
		if (cursor == 0)
			cursor = head;
		else if (cursor->next != 0)
			cursor = cursor->next;
	}

	void erase() {
		if (head == 0 || cursor == 0) 
			return;
		Node *node = cursor->prev;
		
		if (head == cursor) {
			head = head->next;
			if(head!=0)head->prev = 0;

			cursor->next = 0;
			cursor = 0;
		}
		else {
			if (cursor->next != 0) cursor->next->prev = cursor->prev;
			if (cursor->prev != 0) cursor->prev->next = cursor->next;
			cursor = cursor->prev;
		}
	}

	void print() {
		Node *node = head;
		while (node) {
			cout << node->val;
			node = node->next;
		}
	}
};

List list;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		list.cursor = 0;
		list.head = 0;
		nCnt = 0;
		string line;
		cin >> line;
		for (register int i = 0; i < line.size(); ++i) {
			if (line[i] == '<') {
				list.shiftLeft();
			}
			else if (line[i] == '>') {
				list.shiftRight();
			}
			else if (line[i] == '-') {
				list.erase();
			}
			else
				list.push(newNode(line[i]));
		}
		list.print();
		cout << '\n';
	}
}