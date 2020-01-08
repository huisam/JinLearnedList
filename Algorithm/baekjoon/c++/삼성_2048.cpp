#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;
int n;
long long board[20][20];
long long test_board[20][20];
long long max_num = 0;

void left() {
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n - 1; i++)
			for (int a = i + 1; a < n; a++) {
				if (test_board[j][i] && test_board[j][i] == test_board[j][a]) {
					bool ok = true;
					for (int z = i + 1; z < a; z++)
						if (test_board[j][z] != 0) {
							ok = false;
							break;
						}
					if (ok) {
						test_board[j][i] += test_board[j][a];
						test_board[j][a] = 0;
					}
				}
				if (test_board[j][i] == 0 && test_board[j][a]) {
					test_board[j][i] = test_board[j][a];
					test_board[j][a] = 0;
				}
			}
}
void right() {
	for (int j = n-1; j >= 0; j--)
		for (int i = n - 1; i > 0 ; i--)
			for (int a = i - 1; a >= 0; a--) {
				if (test_board[j][i] && test_board[j][i] == test_board[j][a]) {
					bool ok = true;
					for (int z = i - 1; z > a; z--)
						if (test_board[j][z]!=0) {
							ok = false;
							break;
						}
					if (ok) {
						test_board[j][i] += test_board[j][a];
						test_board[j][a] = 0;
					}
				}
				if (test_board[j][i] == 0 && test_board[j][a]) {
					test_board[j][i] = test_board[j][a];
					test_board[j][a] = 0;
				}
			}
}
void up() {
	for (int j = n - 1; j >= 0; j--)
		for (int i = n - 1; i > 0; i--)
			for (int a = i - 1; a >= 0; a--) {
				if (test_board[i][j] && test_board[i][j] == test_board[a][j]) {
					bool ok = true;
					for (int z = i - 1; z > a; z--)
						if (test_board[z][j]!=0) {
							ok = false;
							break;
						}
					if (ok) {
						test_board[i][j] += test_board[a][j];
						test_board[a][j] = 0;
					}
				}
				if (test_board[i][j] == 0 && test_board[a][j]) {
					test_board[i][j] = test_board[a][j];
					test_board[a][j] = 0;
				}
			}
}

void down() {
	for (int j = n - 1; j >= 0; j--)
		for (int i = 0; i < n - 1; i++)
			for (int a = i + 1; a < n; a++) {
				if (test_board[i][j] && test_board[i][j] == test_board[a][j]) {
					bool ok = true;
					for (int z = i + 1; z < a; z++)
						if (test_board[z][j]!=0) {
							ok = false;
							break;
						}
					if (ok) {
						test_board[i][j] += test_board[a][j];
						test_board[a][j] = 0;
					}
				}
				if (test_board[i][j] == 0 && test_board[a][j]) {
					test_board[i][j] = test_board[a][j];
					test_board[a][j] = 0;
				}
			}
}

void test(vector<int> now) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			test_board[i][j] = board[i][j];

	for (int i = 0; i < 5; i++) {
		if (now[i] == 1)
			left();
		else if (now[i] == 2)
			right();
		else if (now[i] == 3)
			up();
		else if (now[i] == 4)
			down();
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			max_num = max(max_num, test_board[i][j]);
}

void go() {
	queue<vector<int>> q;
	vector<int> one(5);
	q.push(one);
	while (!q.empty()) {
		vector<int> now = q.front();
		q.pop();
		if (now[0] == 0) 
			for (int i = 1; i <= 4; i++) {
				now[0] = i;
				q.push(now);
			}
		else if (now[1] == 0) 
			for (int i = 1; i <= 4; i++) {
				now[1]= i;
				q.push(now);
			}
		else if (now[2] == 0)
			for (int i = 1; i <= 4; i++) {
				now[2] = i;
				q.push(now);
			}
		else if (now[3] == 0)
			for (int i = 1; i <= 4; i++) {
				now[3] = i;
				q.push(now);
			}
		else if (now[4] == 0)
			for (int i = 1; i <= 4; i++) {
				now[4] = i;
				q.push(now);
			}
		else 
			test(now);
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	go();
	cout << max_num << '\n';
}