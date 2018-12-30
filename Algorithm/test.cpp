#include<deque>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
#include<map>
#include<string>
using namespace std;

int main() {
	deque<int> q;
	q.push_back(22);
	q.push_front(25);
	q.push_back(40);

	priority_queue<int,vector<int>, less<int>> q1;
	q1.push(222);
	q1.push(4);
	q1.push(1);
	q1.push(500);

	map<string, int> m;
	m["GGOOOD"] = 5;
	m["GG"] = 1;
	m.insert(make_pair("TT", 40));
	if (m.find("TT") == m.end())
		cout << "Not found" << '\n';
	else
		cout << m.find("TT")->first << " " << m.find("TT")->second << '\n';

	for (auto v : m)
		cout << v.first << " : " << v.second << '\n' ;


	while (!q1.empty()) {
		cout << q1.top() << ' ';
		q1.pop();
	}
	cout << '\n';

	if (find(q.begin(), q.end(), 42) == q.end())
		cout << "not found" << '\n';
	cout << count(q.begin(), q.end(), 23) << '\n';
}