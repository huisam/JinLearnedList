#include<iostream>
#include<vector>

using namespace std;

long long d[33][33][3]; // 0 가로 1 세로 2 대각선, d = 이곳으로 갈 수 있는 경우의 수
int n;
vector<vector<int>> map;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	map.resize(n+1);
	for (int i = 1; i <= n; i++) {
		map[i].resize(n+1);
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}
	d[1][2][0] = 1; // 초기 경우의수
	for (int i = 3; i <= n; i++){ // 1행은 3부터
		if (map[1][i] != 1) { // 벽이 아닐때
			d[1][i][0] = d[1][i - 1][0] + d[0][i - 1][2]; // 처음에는 가로만 저장(세로 대각선은 못와)
		}
	}

	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (map[i][j] != 1) { // 각각의 대하여 가로 세로 갱신
				d[i][j][0] = d[i][j - 1][0] + d[i][j-1][2];
				d[i][j][1] = d[i - 1][j][1] + d[i-1][j][2];
				if(map[i-1][j] != 1 && map[i][j-1] != 1) // 대각선은 조건 따지고
					d[i][j][2] = d[i - 1][j - 1][0] + d[i-1][j - 1][1] + d[i - 1][j - 1][2];
			}
		}
	}
	
	cout << d[n][n][0] + d[n][n][1] + d[n][n][2] << '\n'; // 합산 출력
}