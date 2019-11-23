#include<iostream>

using namespace std;

#define MAX_NODE 10000

struct Node {
	int val;
	Node *next;
	Node *prev;
};

Node pool[MAX_NODE];
int nCnt;

Node *newNode(const int val) {
	Node *n = &pool[nCnt++];
	n->val = val;
	n->prev = 0;
	n->next = 0;
	return n;
}

struct LinkedList {
	Node *head;
	Node *tail;

	void init() {
		head = newNode(-987654321);
		tail = newNode(-987654321);
		head->next = tail;
		tail->prev = head;
	}

	void push_back(const int val) {
		Node *node = newNode(val);
		
		node->prev = tail->prev;
		node->next = tail;

		tail->prev->next = node;
		tail->prev = node;
	}

	void push_front(const int val) {
		Node *node = newNode(val);

		node->next = head->next;
		node->prev = head;

		head->next->prev = node;
		head->next = node;
	}

	Node *findSeq(const int val) {
		Node *itr = head;
		while (itr->next) {
			if (val <= itr->next->val)
				return itr->next;

			itr = itr->next;
		}
		return itr;
	}

	void push_sequence(const int val) {
		Node *node = newNode(val);
		Node *findNode = findSeq(val);

		node->prev = findNode->prev;
		node->next = findNode;

		findNode->prev->next = node;
		findNode->prev = node;
	}

	void printList() {
		Node *itr = head->next;
		while (itr->next) {
			cout << itr->val << ' ';
			itr = itr->next;
		}
		cout << '\n';
	}
};

LinkedList list;

int main() {
	list.init();
	list.push_back(2);
	list.push_back(5);
	list.push_back(8);
	list.push_back(1);
	list.printList();

	list.init();
	list.printList();

	list.push_sequence(3);
	list.push_sequence(1);
	list.push_sequence(8);
	list.push_sequence(2);
	list.printList();
}