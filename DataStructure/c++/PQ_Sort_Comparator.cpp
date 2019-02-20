#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;
struct Node {
	int x;
	int y;
	int val;
	Node(int _x, int _y, int _val) :x(_x), y(_y), val(_val) {}

};
struct cmp {
	bool operator()(Node a, Node b) {
		if (a.x == b.x) {
			if (a.y == b.y) {
				return a.val > b.val;
			}
			else return a.y > b.y;
		}
		else return a.x > b.x;
	}
};
bool pred(Node a, Node b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			return a.val > b.val;
		}
		else return a.y > b.y;
	}
	else return a.x > b.x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<Node,vector<Node>,cmp> pq;
	pq.push(Node(3, 2, 5));
	pq.push(Node(4, 2, 5));
	pq.push(Node(5, 3, 4));
	pq.push(Node(6, 2, 5));
	pq.push(Node(3, 4, 5));
	pq.push(Node(3, 2, 7));
	while (!pq.empty()) {
		cout << pq.top().x << ' ' << pq.top().y << ' ' << pq.top().val << '\n';
		pq.pop();
	}
	cout << '\n';
	vector<Node> arr;
	arr.push_back(Node(3, 2, 5));
	arr.push_back(Node(4, 2, 5));
	arr.push_back(Node(5, 3, 4));
	arr.push_back(Node(6, 2, 5));
	arr.push_back(Node(3, 4, 5));
	arr.push_back(Node(3, 2, 7));
	sort(arr.begin(), arr.end(), pred);
	for (auto v : arr) {
		cout << v.x << ' ' << v.y << ' ' << v.val << '\n';
	}
		
}