#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> d(n + 1);
	if (n == 1)
		cout << 0 << endl;
	else if (n == 2)
		cout << 3 << endl;
	else {
		d[1] = 0;
		d[2] = 3;
		for (int i = 3; i <= n; i++) 
			for (int j = 1; 2 * j < i; j++) {
				if (j == 1)
					d[i] += d[i - 2 * j] * 3;
				else
					d[i] += d[i - 2 * j] * 3;
			}
		cout << d[n] << endl;
	}


}