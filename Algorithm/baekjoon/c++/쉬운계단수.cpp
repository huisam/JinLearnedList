#include<iostream>
#include<string>
#include<vector>

using namespace std;

long long MOD = 1000000000;

int main()
{
	vector<vector<long long>> d(101,vector<long long>(10,0));
	int n;
	cin >> n;
	for (auto &v : d[1])
		v = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= MOD;
		}
	long long ans = 0;
	if (n == 1)
	{
		cout << 9 << endl;
		return 0;
	}
	for (auto v : d[n])
		ans += v;
	cout << ans % MOD << endl;
	return 0;

}