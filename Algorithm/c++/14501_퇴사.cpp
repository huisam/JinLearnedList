#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> t(n);
	vector<int> p(n);
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
	
	for (int i = 0; i <= n; i++){
		if(i != 0)
			d[i] = max(d[i], d[i - 1]);
		if (i == n || i + t[i] > n)
			continue;
		d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
	}
	cout << *max_element(d.begin(), d.end()) << '\n';

}