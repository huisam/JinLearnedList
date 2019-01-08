#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> num(n);
	for (auto &v : num)
		cin >> v;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j + i < n; j++)
		{
			sum += num[i + j];
			if (sum == m)
				count++;
			if (sum >= m)
				break;
		}
	}
	cout << count << '\n';
}