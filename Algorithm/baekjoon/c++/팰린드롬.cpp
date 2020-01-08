#include<vector>
#include<iostream>

using namespace std;

int check_bf(vector<int> &number, int x, int y)
{
	while (!((y - x) < 0)) {
		if (number[x] == number[y])
		{
			y--;
			x++;
			continue;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	int n, m;
	cin >> n;
	vector<int> number(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> number[i];
	vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
		d[i][i] = 1;
	for (int i = 1; i < n; i++)
		if (number[i] == number[i + 1])
			d[i][i + 1] = 1;

	for (int k = 3; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (number[i] == number[j] && d[i + 1][j - 1] == 1)
				d[i][j] = 1;
		}
	}


	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << d[x][y] << '\n';
	}
}