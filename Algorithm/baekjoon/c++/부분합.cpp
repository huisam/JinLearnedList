#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<long long> num(n+1);
	vector<int> set;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int left = 0, right = 0;
	long long sum = num[0];
	while (left <= right && right < n) {
		if (sum < s)
		{
			right++;
			sum += num[right];
		}
		else if (sum == s)
		{
			set.push_back(right - left + 1 );
			right++;
			sum += num[right];
		}
		else {
			set.push_back(right - left + 1);
			sum -= num[left];
			left++;
		}
	}
	if (set.empty())
		cout << 0 << '\n';
	else
		cout << *min_element(set.begin(), set.end()) << '\n';
}