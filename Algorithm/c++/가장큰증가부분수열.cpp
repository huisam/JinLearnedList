#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> num(n);
	for (auto &v : num)
		cin >> v;
	vector<int> d(n);

	for (int i = 0; i < n; i++) {
		d[i] = num[i];
		for (int j = 0; j < i; j++)
			if (num[i] > num[j] && d[i] < d[j]+num[i])
				d[i] = d[j] + num[i];

	}
	cout << *max_element(d.begin(), d.end()) << endl;
}