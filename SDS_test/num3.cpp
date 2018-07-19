#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	ifstream fileopen;
	fileopen.open("test3.txt");
	int test_case, N;
	fileopen >> test_case;


	for (int i = 0; i < test_case; i++)
	{
		int start, jump, rest,number;
		fileopen >> N >> start >> jump >> rest;
		
		int count = 0;
		vector<int>rest_page(rest);
		for (int a = 0; a < rest; a++)
		{
			fileopen >> number;
			rest_page[a] = number;
		}

		for (int num = start; num < N; num += jump+1)
		{
			for (int j = 0; j < rest; j++)
			{
				if (num == rest_page[j])
					count++;
			}
		}
		

		cout << "#" << i + 1 << " " << count << endl;
		vector<int>().swap(rest_page);


	}

	return 0;
}
