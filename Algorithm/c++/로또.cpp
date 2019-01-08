#include<vector>
#include<iostream>

using namespace std;
vector<int> lotto;
					// 인덱싱, 개수를 인자로
void answer(vector<int> &data, int idx, int goal)
{
	// 답을 찾았을때
	if (goal == 6)
	{
		for (auto v : lotto)
			cout << v << " ";
		cout << endl;
		return;
	}
	// 서치하는 범위가 초과 되었을때
	if (idx == data.size())
		return;

	lotto.push_back(data[idx]);
	answer(data, idx + 1, goal+1);
	lotto.pop_back();
	answer(data, idx + 1, goal);
}

int main()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		vector<int> data(n);
		for (int i = 0; i < n; i++)
			cin >> data[i];
		answer(data, 0, 0);
		cout << endl;
	}
}