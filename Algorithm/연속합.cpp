#include<vector>
#include<iostream>
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
	d[0] = num[0];
	for (int i = 1; i < n; i++) {
		d[i] = num[i];
		if (i == 0)continue;
		if (d[i] < d[i - 1] + num[i])
			d[i] = d[i - 1] + num[i];
		

	}
	cout << *max_element(d.begin(), d.end()) << endl;
}