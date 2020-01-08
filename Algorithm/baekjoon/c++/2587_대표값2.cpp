#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	cout << sum / 5 << '\n';
	for (int i = 1; i < 5; i++){
		int key = arr[i];
		int j = i - 1;
		for (; j >= 0 && key < arr[j]; j--){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
	cout << arr[2];
}