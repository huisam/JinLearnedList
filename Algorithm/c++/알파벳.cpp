#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;
vector<string> board(21);
map<char, bool> check;
int row, colum;
int max_value = 0;
void answer(int x, int y, int ans)
{
	if (x < 0 || x >= colum || y < 0 || y >= row)
		return;
	if (!check[board[y][x]])
	{
		ans += 1;
		check[board[y][x]] = true;
		answer(x + 1, y, ans);
		answer(x - 1, y, ans);
		answer(x, y + 1, ans);
		answer(x, y - 1, ans);
		if (ans > max_value)
			max_value = ans;
		check[board[y][x]] = false;
	}
	return;
}

int main()
{
	string input;
	scanf(" %d %d", &row, &colum);
	for (int i = 0; i < 26; i++)
		check['A' + i] = 0;
	for (int i = 0; i < row; i++)
		cin >> board[i];
	answer(0, 0, 0);
	cout << max_value << endl;

}