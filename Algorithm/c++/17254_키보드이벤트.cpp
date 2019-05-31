#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> list(m);
    for (int i = 0; i < m; i++) {
        int k, t;
        char a;
        cin >> k >> t >> a;
        list[i] = make_tuple(t, k, a);
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < m; i++) {
        cout << get<2>(list[i]);
    }
}