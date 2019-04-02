#include<vector>
#include<iostream>

using namespace std;
vector<int> lotto;
					// �ε���, ������ ���ڷ�
void answer(vector<int> &data, int idx, int goal)
{
	// ���� ã������
	if (goal == 6)
	{
		for (auto v : lotto)
			cout << v << " ";
		cout << endl;
		return;
	}
	// ��ġ�ϴ� ������ �ʰ� �Ǿ�����
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