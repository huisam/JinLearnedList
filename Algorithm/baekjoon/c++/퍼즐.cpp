#include<queue>
#include<map>
#include<string>
#include<iostream>


using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	int n = 3;
	int start = 0;
	for(int i=1; i<=n; i++)
		for (int j = 1; j <= n; j++) {
			int temp;
			cin >> temp;
			if (temp == 0)
				temp = 9;
			start = start * 10 + temp;
		}
	
	queue<int> data;
	map<int, int> check;
	check[start] = 0;
	data.push(start);
	while (!data.empty()) {
		int now = data.front();
		string now_s = to_string(now);
		data.pop();
		int t = now_s.find('9');
		int y = t / 3;
		int x = t % 3;

		for(int i=0; i<4; i++){
			int dx_x = x + dx[i];
			int dy_y = y + dy[i];
			if (dx_x >= 0 && dx_x < n && dy_y >= 0 && dy_y < n)
			{
				string next_s = now_s;
				swap(next_s[dx_x + 3 * dy_y], next_s[t]);
				int next = stoi(next_s);
				if (check.count(next) == 0)
				{
					check[next] = check[now] + 1;
					data.push(next);
				}
			}
		}
	}
	if (check.count(123456789) == 0)
		cout << -1 << endl;
	else
		cout << check[123456789] << endl;
	return 0;
}