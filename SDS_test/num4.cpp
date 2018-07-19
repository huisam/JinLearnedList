#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>


using namespace std;

int main()
{
	ifstream fileopen;
	fileopen.open("test4.txt");
	int test_case, N;
	fileopen >> test_case;
	

	for (int i = 0; i < test_case; i++)
	{
		int number, times, work_time, test_num, score;
		fileopen >> N >> times >> work_time;

		vector<int>customer_time(N);
		vector<int>customer_danger(N);
		

		for (int j = 0; j < N; j++)
		{
			fileopen >> number;
			customer_time[j] = number;
			fileopen >> number;
			customer_danger[j] = number;
		}
 
		int case_of_her = work_time / times;
		vector<int>score_set(case_of_her);
		int max_score = 0;
		int test_work;
		for (int num2 = 0; num2 < case_of_her; num2++)
		{
			test_num = case_of_her - num2;
			int sum_of_customer = 0;
			score = 10 * test_num;
			test_work = work_time;
			for (int j = 0; j < test_num; j++)
			{
				if (customer_danger[j] != 1)
					test_work -= customer_time[j];
				else
					sum_of_customer += customer_time[j];
			}
			score = score - sum_of_customer + test_work;
			score_set[num2] = score;
		}
		

		cout << "#" << i + 1 << " "  << *max_element(score_set.begin(), score_set.end())<< endl;
		


	}

	return 0;
}
