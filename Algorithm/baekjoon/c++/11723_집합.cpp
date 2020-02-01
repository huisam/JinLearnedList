#include<iostream>
#include<cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long bit = 0L;
	char query[8];
	int n, num;

	cin >> n;
	while (n--) {
		cin >> query;
		if (!strcmp(query, "add")) {
			cin >> num;
			bit |= (1 << num);
		}
		else if (!strcmp(query, "remove")) {
			cin >> num;
			bit &= ~(1 << num);
		}
		else if (!strcmp(query, "check")) {
			cin >> num;
			if (bit & (1 << num)) {
				cout << "1\n";
			}
			else
				cout << "0\n";
		}
		else if (!strcmp(query, "toggle")) {
			cin >> num;
			bit ^= (1 << num);
		}
		else if (!strcmp(query, "all")) {
			bit = (1 << 21) - 1L;
		}
		else {
			bit = 0L;
		}
	}
	return 0;
}