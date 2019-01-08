#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> map(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			else if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
		}

	int chicken_n = chicken.size();
	vector<int> chicken_idx(chicken_n);
	for (int i = 0; i < m; i++)
		chicken_idx[i] = 1;

	sort(chicken_idx.begin(), chicken_idx.end());
	vector<int>distance;
	do {
		int total_sum = 0;
		for (auto v : house) {
			int sum = 101;
			for (int i = 0; i < chicken_n; i++)
				if (chicken_idx[i] == 1)
					sum = min(sum, abs(chicken[i].first - v.first) + abs(chicken[i].second - v.second));
			total_sum += sum;
		}
		distance.push_back(total_sum);
	} while (next_permutation(chicken_idx.begin(), chicken_idx.end()));

	printf("%d\n", *min_element(distance.begin(), distance.end()));
}