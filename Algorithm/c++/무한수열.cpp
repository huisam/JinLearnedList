#include<iostream>
#include<map>
using namespace std;
map<long long, long long> d;
long long n, p, q;

long long go(long long x) {
	if (x == 0) return 1;
	if (d[x]) return d[x];
	else return d[x] = go(x / p) + go(x / q);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> p >> q;

	cout << go(n) << '\n';
}

