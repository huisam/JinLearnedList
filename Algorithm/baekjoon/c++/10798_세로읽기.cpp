#include<iostream>
#include<string>
#include<vector>

using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> a(5);
	vector<int> len(5);
	int max_size = 0;
	for (int i = 0; i < 5; i++){
		cin >> a[i];
		len[i] = a[i].size();
		max_size = max(max_size, len[i]);
	}
	int j = 0;
	while (j < max_size) {
		for (int i = 0; i < 5; i++) {
			if (j >= a[i].size())
				continue;
			cout << a[i][j];
		}
		j++;
	}
	
	
}