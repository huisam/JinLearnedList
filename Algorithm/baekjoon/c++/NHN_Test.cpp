#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>


using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int money = 20000;
	for (int distance; !(ss >> distance).fail(); ) {
		int pay_money;
		if (distance <= 40)
		{
			if (distance < 4)
				break;
			pay_money = 720;
		}
		else
		{
			if (distance > 178)
				break;
			distance -= 40;
			pay_money = 720;
			while (distance > 0)
			{
				distance -= 8;
				pay_money += 80;
			}
		}
		if (pay_money > money)
			break;
		else
			money -= pay_money;

	}
	cout << money;
	// @todo Write your code here.
	cout << endl;
	return 0;
}
