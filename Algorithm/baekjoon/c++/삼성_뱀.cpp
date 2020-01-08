#include<deque>
#include<iostream>

using namespace std;

bool board[101][101];
char time[10001];
int n;
int now_t = 0;

void go(int x, int y, int r){
	deque<pair<int,int>> snake;
	snake.push_back(make_pair(x, y));
	while (1) {

		bool flag = false;

		if (r == 0)
			x += 1;
		else if (r == 1)
			y += 1;
		else if (r == 2)
			x -= 1;
		else if (r == 3)
			y -= 1;

		now_t += 1;

		if (x > n || x <= 0 || y > n || y <= 0)
			break;
		for (int i = 1; i < snake.size(); i++) {
			if (snake[i].first == x && snake[i].second == y)
				flag = true;
		}
		if (flag)
			break;

		if (board[y][x])
		{
			snake.push_front(make_pair(x, y));
			board[y][x] = false;
		}
		else {
			snake.push_front(make_pair(x, y));
			snake.pop_back();
		}

		if (time[now_t] == 'D')
			r = (r + 1) % 4;
		else if (time[now_t] == 'L') {
			r = r - 1;
			if (r == -1)
				r = 3;
		}
	}
}

int main() {
	int k;
	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> y >> x;
		board[y][x] = true;
	}
	int l;
	cin >> l;
	while (l--) {
		int t;
		char r;
		cin >> t >> r;
		time[t] = r;
	}
	go(1, 1, 0);
	cout << now_t << '\n';
}