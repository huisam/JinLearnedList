#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;

vector<bool> edge(1001);
vector<vector<int>> vertex(1001);

void bfs(int n, int v)
{
	fill(edge.begin(), edge.end(), false);
	queue<int> data;
	vector<int> set;
	data.push(v);
	set.push_back(v);
	edge[v] = true;
	while (!data.empty()) {
		int now = data.front();
		data.pop();
		for (auto next : vertex[now])
			if (edge[next] == false)
			{
				data.push(next);
				set.push_back(next);
				edge[next] = true;
			}
	}
	for (auto v : set)
		cout << v << " ";
	cout << endl;
}

void dfs(int v)
{
	fill(edge.begin(), edge.end(), false);
	vector<int> path;
	stack<int> data;
	data.push(v);
	edge[v] = true;
	path.push_back(v);
	while (!data.empty()) {
		int now = data.top();
		data.pop();
 		for (int i = 0; i < vertex[now].size(); i++)
		{
			int next = vertex[now][i];
			if (edge[next] == false)
			{
				edge[next] = true;
				path.push_back(next);
				data.push(now);
				data.push(next);
				break;
			}
		}
		
	}
	for (auto v : path)
		cout << v << " ";
	cout << endl;
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	while (m--) {
		int start_edge, dest_edge;
		cin >> start_edge >> dest_edge;
		vertex[start_edge].push_back(dest_edge);
		vertex[dest_edge].push_back(start_edge);
	}
	for (int i = 1; i < 1001; i++)
		sort(vertex[i].begin(), vertex[i].end());
	dfs(v);
	bfs(n, v);
	return 0;

}