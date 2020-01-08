#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
int n;
int map[20][20];
bool map_check[20][20];
int total_count = 0;

struct fish {
	int size;
	int count;
	fish() :size(2), count(0) {}
	void check() {
		if (count == size) {
			count = 0;
			size++;
		}
	}
};
struct find_set{
	int x;
	int y;
	int dist;
	find_set(int x1, int y1, int dist1) :x(x1), y(y1), dist(dist1) {}
};
bool pred(find_set a, find_set b) {
	if (a.dist < b.dist)
		return true;
	else if (a.dist == b.dist) {
		if (a.y < b.y)
			return true;
		else if (a.y == b.y) {
			if (a.x < b.x)
				return true;
			else
				return false;
		}
	}
	return false;
}

bool check(fish &mine, int &now_x, int &now_y) {
	memset(map_check, false, sizeof(map_check));
	queue<find_set> q;
	vector<find_set> goal;
	q.push(find_set(now_x,now_y,0));
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int now_dist = q.front().dist;
		q.pop();
		if (x < 0 || x >= n || y < 0 || y >= n || mine.size < map[y][x])
			continue;
		if (!map_check[y][x] && mine.size > map[y][x] && map[y][x] != 0) {
			map_check[y][x] = true;
			goal.push_back(find_set(x, y, now_dist));
			continue;
		}
		if (!map_check[y][x]) {
			map_check[y][x] = true;
			q.push(find_set(x, y - 1, now_dist + 1));
			q.push(find_set(x, y + 1, now_dist + 1));
			q.push(find_set(x - 1, y, now_dist + 1));
			q.push(find_set(x + 1, y, now_dist + 1));
		}
	}
	if (goal.empty())
		return false;
	else {
		sort(goal.begin(), goal.end(), pred);
		mine.count++;
		mine.check();
		map[goal[0].y][goal[0].x] = 0;
		total_count += goal[0].dist;
		now_x = goal[0].x;
		now_y = goal[0].y;
		return true;
	}
}

int main() {
	int x,y;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				x = j;
				y = i;
				map[i][j] = 0;
			}
		}
	fish mine;
	while (1) {
		if (!check(mine,x,y))
			break;
	}
	cout << total_count << '\n';
}