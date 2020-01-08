#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

bool node[10000000];
using namespace std;
bool check(int num)
{
	if (num == 0 || num == 1)
		return false;
	else if (num == 2 || num == 3)
		return true;
	bool isprime = true;
	for (int i = 2; i < num; i++)
		if (num % i == 0)
		{
			isprime = false;
			break;
		}
	return isprime;
}
int solution(string numbers) {
	int answer = 0;
    memset(node, false, sizeof(node));
    sort(numbers.begin(), numbers.end());
	do {
		for (int i = 0; i< numbers.size(); i++)
		{
			string idx = numbers.substr(i);
			int int_idx = stoi(idx);
			if (check(int_idx) && !node[int_idx])
			{
				answer++;
				node[int_idx] = true;
			}
		}
	} while (next_permutation(numbers.begin(), numbers.end()));
	return answer;
}
#include<iostream>
int main()
{
	string index = "17";
	cout << solution(index) << endl;
}