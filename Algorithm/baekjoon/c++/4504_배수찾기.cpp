#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	while (k != 0) {
		if (k % n == 0)
			cout << k << " is a multiple of " << n << ".\n";
		else
			cout << k << " is NOT a multiple of " << n << ".\n";
		cin >> k;
	}
}