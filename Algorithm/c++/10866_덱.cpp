#include<iostream>

int mstrcmp(const char *str1, const char *str2) {
	int pos = 0;
	while (str1[pos]) {
		if (str1[pos] != str2[pos])
			break;
		pos++;
	}
	return str1[pos] - str2[pos];
}

using namespace std;

struct Node {
	int val;
	Node *prev;
	Node *next;
};

int nCnt;
Node nodePool[10000];

Node *newNode(int val) {
	Node *n = &nodePool[nCnt++];
	n->val = val;
	n->prev = 0;
	n->next = 0;
	return n;
}

struct Deque {
	Node *head = newNode(0);
	Node *tail = newNode(0);
	int cnt = 0;

	void init() {
		head->next = tail;
		tail->prev = head;
	}

	void push_front(int val) {
		Node *node = newNode(val);
		cnt++;
		
		node->prev = head;
		node->next = head->next;

		head->next->prev = node;
		head->next = node;
	}

	void push_back(int val) {
		Node *node = newNode(val);
		cnt++;

		node->next = tail;
		node->prev = tail->prev;

		tail->prev->next = node;
		tail->prev = node;
	}

	int size() {
		return cnt;
	}

	bool empty() {
		return cnt == 0;
	}

	int pop_front() {
		if (empty()) {
			return -1;
		}

		Node *node = head->next;
		int val = node->val;

		if(node->prev != 0) node->prev->next = node->next;
		if(node->next != 0) node->next->prev = node->prev;

		cnt--;
		return val;
	}

	int pop_back() {
		if (empty()) {
			return -1;
		}

		Node *node = tail->prev;
		int val = node->val;

		if (node->prev != 0) node->prev->next = node->next;
		if (node->next != 0) node->next->prev = node->prev;

		cnt--;
		return val;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return head->next->val;
	}

	int back() {
		if (empty()) {
			return -1;
		}
		return tail->prev->val;
	}
};

Deque deque;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	char text[15];
	int num;
	cin >> n;
	deque.init();
	while (n--) {
		cin >> text;
		if (!mstrcmp(text, "push_back")) {
			cin >> num;
			deque.push_back(num);
		}
		else if (!mstrcmp(text, "push_front")) {
			cin >> num;
			deque.push_front(num);
		}
		else if (!mstrcmp(text, "pop_front")) {
			cout << deque.pop_front() << '\n';
		}
		else if (!mstrcmp(text, "pop_back")) {
			cout << deque.pop_back() << '\n';
		}
		else if (!mstrcmp(text, "size")) {
			cout << deque.size() << '\n';
		}
		else if (!mstrcmp(text, "empty")) {
			cout << deque.empty() << '\n';
		}
		else if (!mstrcmp(text, "front")) {
			cout << deque.front() << '\n';
		}
		else if (!mstrcmp(text, "back")) {
			cout << deque.back() << '\n';
		}
	}
}