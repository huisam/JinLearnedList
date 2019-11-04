#include<iostream>
#include<cstring>

using namespace std;

struct Node {
	Node *prev;
	Node *next;
	int val;
};

Node pool[10000];
int nCnt;

Node *newNode(int val) {
	Node *n = &pool[nCnt++];
	n->prev = 0;
	n->next = 0;
	n->val = val;
	return n;
}

struct List {
	Node *head;
	Node *tail;
	int length;

	void push_back(Node *node) {
		length++;

		if (head == 0) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;

			tail = node;
		}
	}

	void push_front(Node *node) {
		length++;

		if (tail == 0) {
			head = node;
			tail = node;
		}
		else {
			head->prev = node;
			node->next = head;

			head = node;
		}
	}

	bool isEmpty() {
		return length == 0;
	}

	int pop_front() {
		if (isEmpty())
			return -1;

		int val = head->val;
		length--;
		if (head == tail) {
			head = 0;
			tail = 0;
		}
		else {
			Node *node = head;
			head = head->next;

			if (head != 0) head->prev = 0;
			node->next = 0;
		}
		return val;
	}

	int pop_back() {
		if (isEmpty())
			return -1;

		int val = tail->val;
		length--;
		if (head == tail) {
			head = 0;
			tail = 0;
		}
		else {
			Node *node = tail;
			tail = tail->prev;

			if (tail != 0) tail->next = 0;
			node->prev = 0;
		}
		return val;
	}

	int size() {
		return length;
	}
	
	int front() {
		if (head == 0) return -1;
		else return head->val;
	}

	int back() {
		if (tail == 0) return -1;
		else return tail->val;
	}


};

List list;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		char query[11];
		int num;
		cin >> query;
		if (!strcmp(query, "push_back")) {
			cin >> num;
			list.push_back(newNode(num));
		}
		else if (!strcmp(query, "push_front")) {
			cin >> num;
			list.push_front(newNode(num));
		}
		else if (!strcmp(query, "pop_front")) {
			cout << list.pop_front() << '\n';
		}
		else if (!strcmp(query, "pop_back")) {
			cout << list.pop_back() << '\n';
		}
		else if (!strcmp(query, "size")) {
			cout << list.size() << '\n';
		}
		else if (!strcmp(query, "empty")) {
			cout << list.isEmpty() << '\n';
		}
		else if (!strcmp(query, "front")) {
			cout << list.front() << '\n';
		}
		else if (!strcmp(query, "back")) {
			cout << list.back() << '\n';
		}
	}
}