#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string> num;
vector<int> strike;
vector<int> ball;
int n, ans;
bool check[10];

bool isright(string now) {

	for (int i = 0; i < n; i++){
		int nowStrike = 0;
		int nowBall = 0;
		for (int j = 0; j < 3; j++)
		{
			if (now[j] == num[i][j]) nowStrike++;
			else if (now[j] == num[i][(j + 1) % 3] || now[j] == num[i][(j + 2) % 3]) nowBall++;
		}
		if (nowBall != ball[i] || nowStrike != strike[i])
			return false;
	}
	return true;
}

void go(int idx, int len, string now) {
	if (len == 3) {
		if (isright(now)) ans++;
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (!check[i]) {
			check[i] = true;
			now[idx] = i + '0';
			go(idx + 1, len + 1, now);
			now[idx] = '\d';
			check[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	num.resize(n);
	strike.resize(n);
	ball.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i] >> strike[i] >> ball[i];
	}
	go(0, 0, "   ");
	cout << ans << '\n';
}