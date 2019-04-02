#include<set>
#include<unordered_set>
#include<map>
#include<iostream>

using namespace std;

struct Node {
	int x;
	int y;
	int val;
	Node(int _x, int _y, int _v) :x(_x), y(_y), val(_v) {};
	
	bool operator<(const Node a) const { // �ݵ�� operator<(const ) const �� �������̵� ����
		if (x == a.x) {
			if (y == a.y) 
				return val < a.val;
			else
				y < a.y;
		}
		return x < a.x;
	}

	bool operator==(const Node a) const { // Hashset�� �ݵ�� operator == �� hash�Լ��� �������̵� ����
		return (x == a.x && y == a.y && val == a.val);
	}

	friend struct hash<Node>;
};
namespace std {
	template<>
	struct hash<Node> {
		size_t operator() (const Node a) const {
			hash<int> hash_func;
			return a.x ^ (hash_func(a.y) ^ hash_func(a.val));
		}
	};
}


int main() {
	set<Node> s;
	/*  [keypoint] 1.�ݵ�� operator(const) const �� �������̵� �ؾ� treeset���� �����!!!
		�ð� ���⵵ ����
		insert(i) : O(logN)
		erase(i) : O(logN)
		find(i) : O(logN) [ ���� : ã���� �ش� ���� iterator, ������ s.end() ]
		����, ����, �˻� ��� logN�� �ð����⵵!!
	*/
	s.insert(Node(2, 5, 7));
	s.insert(Node(1, 5, 7));
	s.insert(Node(5, 5, 7));
	s.insert(Node(2, 5, 7));
	s.insert(Node(2, 5, 7));
	s.erase(Node(2, 5, 7));
	cout << "[Set]\n";
	if (s.find(Node(5, 5, 7)) != s.end())
		cout << "find it!!\n";
	cout << s.size() << '\n';
	for (auto now : s)
		cout << now.x << ' ' << now.y << ' ' << now.val << '\n';


	unordered_set<Node> ss;
	/* [keypoint] 1.namespace std{template<>hash<Node> ���� size_t operator()�� �������̵� ����}
				  2.operator==(const ) const �� �ݵ�� �������̵�!!
		�ð� ���⵵ ����
		insert(i) : O(1) - ��� ~ O(N) - �־�
		erase(i) : O(1) - ��� ~ O(N) - �־�
		find(i) : O(1) - ��� ~ O(N) - �־�
	*/
	ss.insert(Node(2, 5, 7));
	ss.insert(Node(2, 5, 7));
	ss.insert(Node(3, 5, 7));
	ss.insert(Node(2, 5, 7));
	ss.insert(Node(2, 4, 7));
	ss.insert(Node(2, 5, 7));
	cout << "[HashSet]\n";
	cout << ss.size() << '\n';
	for (auto now : ss)
		cout << now.x << ' ' << now.y << ' ' << now.val << '\n';

	map<Node, int> m;
	/* �ð����⵵ ����
		set�� ������ �ð����⵵�� ������
		����,����,Ž�� ��� O(logN)
	*/
	m[Node(2, 4, 6)] = 2;
	m[Node(2, 4, 6)] = 2;
	m.insert({ Node(1, 4, 6) , 2 });
	m.insert(make_pair(Node(2, 4, 6), 3));
	m[Node(5, 4, 6)] = 2;
	m[Node(2, 7, 6)] = 2;
	cout << "[Map]\n";
	cout << "(2,7,6)Node�� Ű�� : " << m.find(Node(2, 7, 6))->second << '\n';
	cout << m.size() << '\n';
	for (auto now : m)
		cout << now.first.x << ' ' << now.first.y << ' ' << now.first.val << " : " << now.second << '\n';
}