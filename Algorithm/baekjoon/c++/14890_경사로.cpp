#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, l, ans;

void go(vector<vector<int>> &map, int x, int y, int r) {
	if (r == 0) { // y로 증가
		int prev = map[x][y]; // 이전 값 저장
		int cnt = 1; // 이전 값의 수량 저장
		for (int i = 1; i < n; i++){
			if (prev == map[x][i]) { // 같으면 수량만 세기
				cnt++;
			}
			else { // 다르면
				if (prev - map[x][i] == -1 && cnt >= l) { // 값이 증가할경우, 수량을 기반으로 판별
					prev = map[x][i];
					cnt = 1;
				}
				else if (prev - map[x][i] == 1 && i + l - 1 < n) { // 값이 감소할 경우, 미래를 내다봐야함
					int t = i;
					while (t != i + l) { // 계속 같아야함
						if (map[x][i] != map[x][t])
							return;
						t++;
					}
					i = t - 1;
					prev = map[x][i];
					cnt = 0; // 더이상 해당 블록은 쓸 수 없으므로 0개부터
				}
				else
					return;
			}
		}
		ans++;
	}
	else { // x로 증가, 위와 동일
		int prev = map[x][y];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (prev == map[i][y]) {
				cnt++;
			}
			else {
				if (prev - map[i][y] == -1 && cnt >= l) {
					prev = map[i][y];
					cnt = 1;
				}
				else if (prev - map[i][y] == 1 && i + l - 1 < n ) {
					int t = i;
					while (t != i + l) {
						if (map[i][y] != map[t][y]) 
							return;
						t++;
					}
					i = t - 1;
					prev = map[i][y];
					cnt = 0;
				}
				else
					return;
			}
		}
		ans++;
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l;
	vector<vector<int>> map(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++){
		go(map, i, 0, 0);
		go(map, 0, i, 1);
	}
	cout << ans << '\n';
	return 0;
}