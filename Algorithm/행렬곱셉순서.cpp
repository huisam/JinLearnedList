#include<iostream>
#include<vector>

using namespace std;

long long d[501][501];
vector<pair<int, int>> a(501);

int go(int s, int g) {
	if (s == g)
		return 0;
	if (d[s][g])
		return d[s][g];
	if (s + 1 == g)
		return a[s].first * a[g].first * a[g].second;
	d[s][g] = -1;
	for (int k = s; k < g; k++)
	{
		int tmp1 = go(s, k);
		int tmp2 = go(k+1, g);
		if ( d[s][g] == -1 || d[s][g] > tmp1 + tmp2 + a[s].first * a[k].second * a[g].second)
			d[s][g] = tmp1 + tmp2 + a[s].first * a[k].second * a[g].second;
	}

	return d[s][g];
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	cout << go(1,n) << '\n';
}