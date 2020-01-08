#include<cstdio>
int *arr;
int *temp;

void mergeSort(int left, int right) {
	if (right - left == 0)
		return;
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	int l = left; int r = mid + 1; int k = left;
	while (l <= mid && r <= right) {
		if (arr[l] < arr[r])
			temp[k++] = arr[l++];
		else
			temp[k++] = arr[r++];
	}
	if (l <= mid) {
		while (l <= mid) temp[k++] = arr[l++];
	} else {
		while (r <= right) temp[k++] = arr[r++];
	}
	for (int i = left; i <= right; i++)
		arr[i] = temp[i];
}

int main() {
	int n;
	scanf("%d", &n);
	arr = new int[n];
	temp = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}