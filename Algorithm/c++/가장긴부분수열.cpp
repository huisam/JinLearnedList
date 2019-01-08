#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> number(n);
	for (auto &v : number)
		cin >> v;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++)
			if (number[j] < number[i] && d[j] + 1>d[i])
				d[i] = d[j] + 1;
	}
	cout << *max_element(d.begin(), d.end()) << endl;
}