#include<iostream>
#include<string>
using namespace std;

long long d[5001][2];
long long mod = 1000000;
int main()
{
	string number;
	cin >> number;
	
	if (stoi(number) == 0)
	{
		cout << 0 << '\n';
		return 0;
	}

	d[1][0] = 1LL;
	d[0][0] = 1LL;
	for (int i = 0; i < number.size()-1; i++)
	{
		int now = stoi(number.substr(i,2));
		if (now >= 1 && now <= 26 && now %10 != 0)
		{
			d[i + 2][0] = (d[i + 1][0] + d[i + 1][1]) % mod;
			d[i + 2][1] = (d[i][0] + d[i][1]) % mod;
		}
		else
			d[i + 2][0] = (d[i + 1][0] + d[i + 1][1]) % mod;

	}
	cout << d[number.size()][0] + d[number.size()][1] << '\n';

}