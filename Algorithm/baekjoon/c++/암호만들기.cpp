#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool check(string password)
{
	int ja = 0;
	int mo = 0;
	for (int i = 0; i < password.size(); i++)
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i'
			|| password[i] == 'o' || password[i] == 'u') {
			mo++;
		}
		else
			ja++;

	return (ja >= 2 && mo >= 1);
}

void go(int n, vector<char>&alpa, string password, int l)
{
	if (password.size() == l) {
		if (check(password))
			cout << password << endl;
		return;
	}
	if (n>= alpa.size()) return;
	go(n+1, alpa, password + alpa[n], l);
	go(n+1, alpa, password, l);
}

int main()
{
	int l, c;
	cin >> l >> c;
	vector<char> alpa;
	char input;
	for (int i = 0; i < c; i++) {
		cin >> input;
		alpa.push_back(input);
	}
	sort(alpa.begin(), alpa.end());
	string password = "";
	go(0, alpa, password, l);

}