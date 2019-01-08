#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> yeonsan(4);
	vector<int> yeonsan_set;
	vector<long long> set;
	for (auto &v : num)
		cin >> v;
	for (auto &y : yeonsan)
		cin >> y;
	for (int i = 0; i < 4; i++)	{
		int d = yeonsan[i];
		while (d--)
			yeonsan_set.push_back(i);
	}
	do
	{
		long long sum = num[0];
		for (int i = 0; i < yeonsan_set.size(); i++)
		{
			if (yeonsan_set[i] == 0)
				sum += num[i + 1];
			else if (yeonsan_set[i] == 1)
				sum -= num[i + 1];
			else if (yeonsan_set[i] == 2)
				sum *= num[i + 1];
			else
				sum /= num[i + 1];
		}
		set.push_back(sum);
	} while (next_permutation(yeonsan_set.begin(), yeonsan_set.end()));
	cout << *max_element(set.begin(), set.end()) << '\n' << *min_element(set.begin(), set.end()) << '\n';
}