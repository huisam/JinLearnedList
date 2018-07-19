#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
static int n, m, c1, c2, r1, r2;

int minimum(int &num1, int &max)
{
	int number;
	if (num1 < (max / 2))
		number = 0;
	else
		number = max - 1;

	return number;
}

int main()
{
	ifstream fileopen;
	fileopen.open("test.txt");
	int test_case;
	fileopen >> test_case;
	
	
	for (int i = 0; i < test_case; i++)
	{
		
		fileopen >> n >> m >> r1 >> c1 >> r2 >> c2;

		int cost = 0;
		int min_x_1 = minimum(r1,n);
		int min_x_2 = minimum(r2, n);
		int min_y_1 = minimum(c1, m);
		int min_y_2 = minimum(c2, m);
			
		if (abs(r1 - r2) <= (abs(min_x_1 - r1) + abs(min_x_2 - r2)))
			cost += abs(r1 - r2);
		else
			cost += abs(min_x_1 - r1) + abs(min_x_2 - r2) +1;

		if (abs(c1 - c2) <= (abs(min_y_1 - c1) + abs(min_y_2 - c2)))
			cost += abs(c1 - c2);
		else
			cost += abs(min_y_1 - c1) + abs(min_y_2 - c2) +1;

		cout << "#" << i + 1 << " " << cost << endl;
	}

	return 0;
}
