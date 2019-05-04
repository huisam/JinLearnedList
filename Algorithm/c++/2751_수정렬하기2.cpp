#include<cstdio>
int *arr;

void quicksort(int left, int right) {
	if (left >= right)
		return;
	int l = left - 1;
	int r = right + 1;
	int mid = arr[(l + r) / 2];
	while (true) {
		while (arr[++l] < mid);
		while (arr[--r] > mid);
		if (l >= r)
			break;
		int temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}
	quicksort(left, l - 1);
	quicksort(r + 1, right);
}

int main() {
	int n;
	scanf("%d", &n);
	arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}