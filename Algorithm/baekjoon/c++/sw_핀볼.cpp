#include<vector>
#include<iostream>

using namespace std;

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
int n;
struct boll {
	int x;
	int y;
	int r;
	boll(int _x, int _y, int _r) :x(_x), y(_y), r(_r) {};
	void next();
};
void boll::next()
{
	switch (r) {
	case UP:
		y -= 1;
		break;
	case DOWN:
		y += 1;
		break;
	case LEFT:
		x -= 1;
		break;
	case RIGHT:
		x += 1;
		break;
	}
}

void check(vector<vector<int>> map, boll &next, int block, int x, int y, int r, int &score)
{
	switch (block) {
	case 1:
		if (next.r == RIGHT) {
			next.x = x;
			next.r = LEFT;
			score++;
		}
		else if (next.r == UP) {
			next.y = y;
			next.y = DOWN;
			score++;
		}
		else if (next.r == DOWN) {
			next.x += 1;
			next.r = RIGHT;
			score++;
		}
		else {
			next.y -= 1;
			next.r = UP;
			score++;
		}
		break;

	}
}

void boll_start(vector<vector<int>> map, int x, int y, int r)
{
	boll bl_start(x, y, r);
	int score = 0;
	while (1) {
		boll bl_next(x, y, r);
		bl_next.next();
		if (bl_next.x == bl_start.x && bl_next.y == bl_start.y)
			break;
		if (map[bl_next.y][bl_next.x] == -1) {
			score = -1;
			break;
		}
		if (bl_next.x < 0) {
			bl_next.x = x;
			bl_next.r = RIGHT;
			score++;
		}
		else if (bl_next.x >= n) {
			bl_next.x = x;
			bl_next.r = LEFT;
			score++;
		}
		else if (bl_next.y < 0) {
			bl_next.y = y;
			bl_next.y = DOWN;
			score++;
		}
		else if (bl_next.y >= n) {
			bl_next.y = y;
			bl_next.y = UP;
			score++;
		}
		else {
			check(map, bl_next, map[bl_next.y][bl_next.x],x,y,r,score);
		}
	
	}
}

int main()
{
	int t;
	cin >> t;
	for (int a = 1; a <= t; a++)
	{
		cin >> n;
		vector<vector<int>> b(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> b[i][j];

	}
}