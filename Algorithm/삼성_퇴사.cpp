#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int T[16];
int P[16];
int n;
vector<int> ans;

void check(int idx, int price) {
	if (idx > n) {
		ans.push_back(price);
		return;
	}
	if (T[idx] + idx <= n+1) 
		check(idx + T[idx], price + P[idx]);
	check(idx + 1, price);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &T[i], &P[i]);
	check(1, 0);
	printf("%d\n", *max_element(ans.begin(), ans.end()));
}