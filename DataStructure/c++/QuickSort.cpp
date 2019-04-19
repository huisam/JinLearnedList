#include<time.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
/*
	데이터가 1천만개 기준
	구현 sort : 798ms
	라이브러리 sort : 4663ms
*/
const int SIZE = 10000000;

int arr1[SIZE];
int arr2[SIZE];

void makeData() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		arr1[i] = arr2[i] = rand() % 100;
	}
}

void printData() {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << '\n';
}

void quickSort(int left, int right) {
	if (left >= right) return;

	int l = left - 1;
	int r = right + 1;
	int mid = arr1[(l + r) / 2];
	while (true) {
		while (arr1[++l] < mid);
		while (arr1[--r] > mid);
		if (l >= r)
			break;
		int temp = arr1[l];
		arr1[l] = arr1[r];
		arr1[r] = temp;
	}
	quickSort( left, l - 1);
	quickSort( r+1, right);

}

int main() {
	makeData();
	time_t now = clock();
	quickSort(0, SIZE-1);
	cout << "My first sort is " << clock() - now << "ms\n";
	now = clock();
	sort(arr2, arr2 + SIZE);
	cout << "STL sort is " << clock() - now << "ms\n";
}