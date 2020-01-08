#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct node {
	int x; int y; int r; int k;
};
vector<node> nodes(1000);
int n;
void detect_obj(int &score) {
	bool find;
	for (int i = 0; i < n; i++) {
		find = false;
		if (nodes[i].k == 0)
			continue;
		for (int j = i + 1; j < n; j++) {
			if (nodes[j].k == 0)
				continue;
			if (nodes[i].x == nodes[j].x && nodes[i].y == nodes[j].y){
				find = true;
				score += nodes[j].k;
				nodes[j].k = 0;
			}
			if (nodes[i].x == nodes[j].x && abs(nodes[i].y - nodes[j].y)<=1 && nodes[i].r <= 1 && nodes[j].r <= 1 && abs(nodes[i].r - nodes[j].r) <= 1) {
				find = true;
				score += nodes[j].k;
				nodes[j].k = 0;
			}
			if (nodes[i].y == nodes[j].y && abs(nodes[i].x - nodes[j].x) <= 1 && nodes[j].r >= 2 && nodes[i].r >= 2 && abs(nodes[i].r - nodes[j].r) <= 1) {
				find = true;
				score += nodes[j].k;
				nodes[j].k = 0;
			}
		}
		if (find) {
			score += nodes[i].k;
			nodes[i].k = 0;
		}
	}
}

void move_node() {
	for (int i = 0; i < n; i++) {
		nodes[i].x += dx[nodes[i].r];
		nodes[i].y += dy[nodes[i].r];
		}
}

bool check()
{
	for (int i = 0; i < n; i++)
		if (nodes[i].k != 0)
			return false;
	return true;
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int x,y,r,k;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> r >> k;
			nodes[i] = { x,y,r,k };
		}
		int time = 2000;
		int score = 0;
		while (time--) {
			move_node();
			detect_obj(score);
			if (check())
				break;
		}
		cout << '#' << t << ' ' << score << '\n';

	}
}