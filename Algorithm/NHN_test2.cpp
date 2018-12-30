#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string line;
	getline(cin, line);  // drop a newline traling n
	vector<vector<int>> map(1001);
	vector<int> final_goal;
	queue<int> data;
	while (n-- > 0) {
		getline(cin, line);
		stringstream ss(line);
		for (int fork; !(ss >> fork).fail(); ) {  // read forks from a note
			if (data.empty())
				data.push(fork);
			else
			{
				int prev_edge = data.front();
				data.pop();
				if(map[prev_edge].empty())
					map[prev_edge].push_back(fork);
				else
					if (map[prev_edge][0] != fork)
					{
						cout << -1 << endl;
						return 0;
					}
				data.push(fork);
			}
			// @todo Write your code here.
		}
		data.pop();
		// @todo Write your code here.
	}
	for (int i = 1; i < 1001; i++)
		if (!map[i].empty())
		{
			int prev = i;
			while (!map[prev].empty())
			{
				prev = map[prev][0];
			}
			final_goal.push_back(prev);
		}
	sort(final_goal.begin(), final_goal.end());
	final_goal.erase(unique(final_goal.begin(), final_goal.end()), final_goal.end());
	for (auto v : final_goal)
		cout << v << " ";
	cout << endl;
	// @todo Write your code here.
	return 0;
}
