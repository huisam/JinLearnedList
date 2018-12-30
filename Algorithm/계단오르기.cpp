#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &v : a)
		cin >> v;
	vector<vector<int>> d(n, vector<int>(3, 0));

	if (n == 1)
		cout << a[0] << endl;
	else if (n == 2)
		cout << a[0] + a[1] << endl;
	else {
		d[0][1] = a[0];
		d[1][1] = a[1];
		d[1][2] = a[0] + a[1];
		for (int i = 2; i < n; i++)
		{
			d[i][1] = max(d[i - 2][2] + a[i], d[i - 2][1] + a[i]);
			d[i][2] = d[i - 1][1] + a[i];
		}
		cout << max(d[n - 1][1], d[n - 1][2]) << endl;
	}
}