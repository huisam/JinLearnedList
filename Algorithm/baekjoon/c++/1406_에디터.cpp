#include<iostream>
#include<list>
#include<string>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	list<char> ans;
	string now;
	cin >> now;
	for (int i = 0; i < now.size(); i++)
		ans.push_back(now[i]);
	int k;
	auto itr = ans.end();
	cin >> k;
	while (k--) {
		char action;
		cin >> action;
		switch (action){
		case 'P':
			char val;
			cin >> val;
			ans.insert(itr, val); // 해당 iterator에 value삽입
			break;
		case 'L':
			if (itr != ans.begin())
				itr--; // 이전 iterator로
			break;
		case 'D':
			if (itr != ans.end())
				itr++; // 다음 iterator로
			break;
		case 'B':
			if (itr != ans.begin()) {
				itr--;
				itr = ans.erase(itr); // 이전iterator로 가서 값지우고 다시 받아오기
			}
			break;
		}
	}
	for (auto a : ans)
		cout << a;

}