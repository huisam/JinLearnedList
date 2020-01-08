#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, h;
int ans = 4;
vector<vector<int>> line(31, vector<int>(11, 0));

bool test() {
	for (int idx = 1; idx <= n; idx++) {
		int current_idx = idx;
		for (int height = 1; height <= h; height++) {
			if (current_idx - 1 >= 0 && line[height][current_idx - 1])
				current_idx -= 1;
			else if (current_idx < n && line[height][current_idx])
				current_idx += 1;
		}
		if (current_idx != idx)
			return false;
	}
	return true;
}

void test_case(int start_h, int start_w, int cnt ){
	if (cnt > 3)
		return;
	if (test()) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = start_h; i <= h; i++)
		for (int w = 1; w < n; w++) {
			if (i == start_h && w <= start_w)
				continue;
			if (!line[i][w]) {
				line[i][w] = 1;
				test_case(i, w, cnt+1);
				line[i][w] = 0;
			}
		}
}


int main() {

	scanf("%d %d %d", &n, &m, &h);

	while (m--) {
		int number, line_num;
		scanf("%d %d", &number, &line_num);
		line[number][line_num] = 1;
	}

	if (test())
		printf("0\n");
	else {
		for(int i= 1; i<=h; i++)
			for (int w = 1; w < n; w++) 
				if (!line[i][w]){
					line[i][w] = 1;
					test_case(i, w, 1);
					line[i][w] = 0;
			}

		if (ans > 3)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
}