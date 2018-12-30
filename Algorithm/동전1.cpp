#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coins;
	vector<int> d(10001);
	while (n--)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}
	sort(coins.begin(), coins.end());
	d[0] = 1;
	for (auto c : coins)
		for (int i = 1; i <= k; i++)
			if (i - c >= 0)
				d[i] += d[i - c];
	cout << d[k] << '\n';
}