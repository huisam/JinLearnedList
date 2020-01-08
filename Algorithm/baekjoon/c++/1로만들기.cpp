#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < long long int > data(1000000);
	data[1] = 0;
	data[2] = 1;
	data[3] = 1;
	if (n <= 3)
		cout << data[n] << endl;
	else
	{
		for (int i = 4; i <= n; i++)
		{
			if (i % 3 == 0 && data[i/3] < data[i-1])
				data[i] = data[i / 3] + 1;
			else if (i % 2 == 0 && data[i/2] < data[i-1])
				data[i] = data[i / 2] + 1;
			else
				data[i] = data[i - 1] + 1;
		}
		cout << data[n] << endl;
	}
}