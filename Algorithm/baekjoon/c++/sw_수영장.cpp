#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		vector<int> price(4);
		for (auto &p : price)
			cin >> p;
		vector<int> month(12);
		for (auto &v : month)
			cin >> v;
		vector<int> d(13);

		for (int a = 1; a <= 12; a++) {
			if (month[a-1] > 0) {
				d[a] = price[0] * month[a-1];
				if (price[1] < d[a])
					d[a] = price[1];
			}
			d[a] += d[a - 1];
			if(a>=3)
				if (d[a] - d[a - 3] > price[2])
					d[a] = d[a - 3] + price[2];
		}
		if (price[3] < d[12])
			cout << '#' << i << ' ' << price[3] << '\n';
		else
			cout << '#' << i << ' ' << d[12] << '\n';
		vector<int>().swap(d);
		vector<int>().swap(month);
		vector<int>().swap(price);
	}
}