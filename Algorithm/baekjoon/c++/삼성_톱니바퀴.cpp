#include<deque>
#include<cmath>
#include<cstring>
#include<cstdio>

using namespace std;

bool check[4];
deque<deque<int>> tobni(4, deque<int>(8, 0));

void rounding(int idx, int round) {
	if (round == 1) {
		int back = tobni[idx].back();
		tobni[idx].pop_back();
		tobni[idx].push_front(back);
	}
	else {
		int front = tobni[idx].front();
		tobni[idx].pop_front();
		tobni[idx].push_back(front);
	}
	return;
}

int main()
{
	for (int j = 0; j<4; j++)
		for (int i = 0; i < 8; i++)
			scanf("%1d", &tobni[j][i]);
	int k;
	scanf("%d", &k);
	while (k--) {
		int t, r;
		scanf("%d %d", &t, &r);
		memset(check, false, sizeof(check));
		deque<pair<int, int>> q;
		q.push_back(make_pair(t - 1, r));
		while (!q.empty()) {
			int now = q.front().first;
			int round = q.front().second;
			q.pop_front();

			if (check[now])
				continue;
			check[now] = true;
			if (now == 0) {
				if (tobni[now][2] != tobni[now + 1][6]) 
					q.push_back(make_pair(now + 1, -round));
			}
			else if (now == 3) {
				if (tobni[now][6] != tobni[now - 1][2]) 
					q.push_back(make_pair(now - 1, -round));
			}
			else if (now == 2 || now == 1) {
				if (tobni[now][6] != tobni[now - 1][2])
					q.push_back(make_pair(now - 1, -round));

				if (tobni[now][2] != tobni[now + 1][6])
					q.push_back(make_pair(now + 1, -round));
			}
			rounding(now, round);
		}
	}
	int point = 0;
	for (int i = 0; i < 4; i++)
		if (tobni[i][0] == 1)
			point += (int)pow(2, i);
	printf("%d\n", point);

}