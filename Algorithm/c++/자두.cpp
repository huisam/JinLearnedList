#include<cstdio>

int a[1001];
int d[1001][31];
int t, w;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a < b ? b : a; }
int main()
{
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= t; i++) {
		if (a[i] == 1)
			d[i][0] = d[i - 1][0] + 1;
		else
			d[i][0] = d[i - 1][0];

		for (int j = 1; j <= min(w, i); j++) {
			if (j % 2 == a[i] - 1) {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]);
			}
		}
	}
	int max_jadu = 0;
	for (int j = 0; j <= w; j++)
		max_jadu = max(max_jadu, d[t][j]);
	printf("%d\n", max_jadu);
}