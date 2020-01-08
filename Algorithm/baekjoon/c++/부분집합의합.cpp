#include<vector>
#include<iostream>

using namespace std;
bool check[20];
int ans = 0;
void solution(vector<int> &data, int idx, int cnt,int s)
{
	// 검사가 끝낫을 경우의수
	if (idx == data.size()) {
		if (cnt == s)
			ans++;
		return;
	}
	// 다음 경우의 수
	int now = data[idx];
	solution(data, idx + 1, cnt + now, s);
	solution(data, idx + 1, cnt, s);
	return;
}

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> data(n);
	for (auto &v : data)
		cin >> v;
	solution(data, 0, 0, s);
	if (s == 0)
		ans -= 1;
	cout << ans << endl;
}