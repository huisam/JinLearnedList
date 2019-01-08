#include<cstdio>

int podo[10001];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &podo[i]);

	if (n == 1)
		printf("%d\n", podo[1]);
	else if (n == 2)
		printf("%d\n", podo[1]+podo[2]);
	else
	{
		int d[10001][3];
		d[2][0] = 0; d[2][1] = podo[2]; d[2][2] = podo[1] + podo[2];

		for (int i = 3; i <= n; i++)
		{
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = d[i - 1][0] + podo[i];
			d[i][2] = d[i - 1][1] + podo[i];
		}
		int value = max(d[n][0], max(d[n][1], d[n][2]));
		printf("%d\n", value);
	}

}