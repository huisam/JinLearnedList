#include<iostream>

#define MAX_NODE 1000001

using namespace std;

int arr[MAX_NODE];

int findParent(const int num) {
	if (arr[num] == num) return num;
	return arr[num] = findParent(arr[num]);
}

void merge(const int a, const int b) {
	int x = findParent(a);
	int y = findParent(b);

	if (x != y) {
		arr[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (register int i = 1; i <= n; ++i)
		arr[i] = i;

	while (m--) {
		int div, num1, num2;
		cin >> div >> num1 >> num2;

		if (div == 0) {
			merge(num1, num2);
		}
		else {
			int a = findParent(num1);
			int b = findParent(num2);

			if (a == b) {
				cout << "yes\n";
			}
			else
				cout << "no\n";
		}
	
	}

}