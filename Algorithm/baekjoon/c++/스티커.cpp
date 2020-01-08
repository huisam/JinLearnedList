#include<iostream>
#include<algorithm>
using namespace std;

int d[100001][3];
int datas[2][100001] = {};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> datas[i][j];
		d[0][0] = 0;
		d[0][1] = 0;
		d[0][2] = 0;
		for (int i = 1; i <= n; i++)
		{
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + datas[1][i];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + datas[0][i];
		}
		int max_value = max(d[n][0],max( d[n][1], d[n][2]));
		cout << max_value << endl;
	}
}