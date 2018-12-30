#include<cstdio>

int main()
{
	int d[1001] = { 0,1,2 };
	d[1] = 1;
	d[2] = 2;
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
		d[i] = d[i] % 10007;
	}

	printf("%d\n", d[n]);
	return 0;
}