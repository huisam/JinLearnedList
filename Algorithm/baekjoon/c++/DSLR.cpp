#include<queue>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	vector<bool> check(10001);
	vector<int> dist(10001);
	vector<int> from(10001);
	vector<char> how(10001);
	int t;
	cin >> t;
	while (t--) {
		int start, destination;
		cin >> start >> destination;
		fill(check.begin(), check.end(), false);
		fill(dist.begin(), dist.end(), 0);
		fill(dist.begin(), dist.end(), 0);
		fill(how.begin(), how.end(), 0);
		queue<int> data;
		data.push(start);
		dist[start] = 1;
		while (!data.empty()) {
			int now = data.front();
			data.pop();

			int next = (2 * now) % 10000; // function D
			if (check[next] == false)
			{
				data.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'D';
			}

			if (now == 0)
				next = 9999;
			else
				next = now - 1;
			if (check[next] == false)
			{
				data.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'S';
			}
			
			next = (now % 1000) * 10 + (now / 1000);
			if (check[next] == false)
			{
				data.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'L';
			}

			next = (now / 10) + (now % 10) * 1000;
			if (check[next] == false)
			{
				data.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'R';
			}
			if (check[destination] == true)
				break;
		}
		string ans = "";
		while (destination != start)
		{
			ans += how[destination];
			destination = from[destination];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}