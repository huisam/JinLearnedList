#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, k;

struct sets {
	int user;
	int user1;
	int user2;
	sets() {};
	sets(int _0, int _1, int _2) : user(_0), user1(_1), user2(_2) {};
};

struct stay {
	int now;
	int next;
	sets win;
	sets plan;
	stay() { win = sets(); plan = sets(); };
	stay(int _now, int _n, sets wins, sets plans) : now(_now), next(_n), win(wins), plan(plans) {};
	stay(int _now, int _n, int _p, int _p1, int _p2, int _w, int _w1, int _w2) : now(_now), next(_n) {
		win = sets(_w, _w1, _w2);
		plan = sets(_p, _p1, _p2);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vector<vector<int>> rsp(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> user(3, vector<int>(20, 0)); // 0 지우, 1 경희, 2 민호
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> rsp[i][j];

	for (int a = 1; a < 3; a++)
		for (int i = 0; i < 20; i++)
			cin >> user[a][i];

	queue<pair<stay, vector<bool>>> q;

	q.push({ {0, 1, 0, 0 ,0, 0,0,0 }, vector<bool>(n + 1,false) });

	while (!q.empty()) {
		stay nw = q.front().first;
		vector<bool> l = q.front().second;
		
		q.pop();
		// 다른 유저 승리시 
		if (nw.win.user1 == k || nw.win.user2 == k)
			continue;
		//내가 이기면
		else if (nw.win.user == k) {
			cout << 1 << '\n';
			return 0;
		}
		// 어떤 가위바위보를 낼것인지
		if (nw.now == 0 || nw.next == 0) {
			for (int i = 1; i <= n; i++) {
				if (!l[i]) {
					// 다음 상대유저와 다음 지금 유저 고르기
					l[i] = true;
					sets win = nw.win;
					sets plan = nw.plan;
					int now = 0;
					int next = 0;
					if (nw.now == 0 && nw.next == 1) {
						next = 2;
						if (rsp[i][user[1][plan.user1]] == 2) {
							now = 0;
							win.user++;
						}
						else if (rsp[i][user[1][plan.user1]] == 1) {
							now = 1;
							win.user1++;
						}
						else {
							now = 1;
							win.user1++;
						}
						plan.user1++;
					}
					else if (nw.now == 0 && nw.next == 2) {
						next = 1;
						if (rsp[i][user[2][plan.user2]] == 2) {
							now = 0;
							win.user++;
						}
						else if (rsp[i][user[2][plan.user2]] == 1) {
							now = 2;
							win.user2++;
						}
						else {
							now = 2;
							win.user2++;
						}
						plan.user2++;
					}
					else if (nw.now == 1 && nw.next == 0) {
						next = 2;
						if (rsp[user[1][plan.user1]][i] == 2) {
							now = 1;
							win.user1++;
						}
						else if (rsp[user[1][plan.user1]][i] == 1) {
							now = 1;
							win.user1++;
						}
						else {
							now = 0;
							win.user++;
						}
						plan.user1++;
					}
					
					else if (nw.now == 2 && nw.next == 0) {
						next = 1;
						if (rsp[user[2][plan.user2]][i] == 2) {
							now = 2;
							win.user2++;
						}
						else if (rsp[user[2][plan.user2]][i] == 1) {
							now = 2;
							win.user2++;
						}
						else {
							now = 0;
							win.user++;
						}
						plan.user2++;
					}

					q.push({ { now, next, win, plan}, l });
					l[i] = false;
				}
			}
		}
		else {
			sets win = nw.win;
			sets plan = nw.plan;
			int next = 0;
			int now = 0;
		if (nw.now == 1 && nw.next == 2) {
			next = 0;
			if (rsp[user[2][plan.user2]][user[1][plan.user1]] == 2) {
				now = 2;
				win.user2++;
			}
			else if (rsp[user[2][plan.user2]][user[1][plan.user1]] == 1) {
				now = 2;
				win.user2++;
			}
			else {
				now = 1;
				win.user1++;
			}
			plan.user2++;
			plan.user1++;
		}
		else if (nw.now == 2 && nw.next == 1) {
			next = 0;
			if (rsp[user[2][plan.user2]][user[1][plan.user1]] == 2) {
				now = 2;
				win.user2++;
			}
			else if (rsp[user[2][plan.user2]][user[1][plan.user1]] == 1) {
				now = 2;
				win.user2++;
			}
			else {
				now = 1;
				win.user1++;
			}
			plan.user1++;
			plan.user2++;
		}
		
		q.push({ { now, next, win, plan}, l });
		}
	}

	cout << 0 << '\n';
	return 0;
}