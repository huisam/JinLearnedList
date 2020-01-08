#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	int n, total, sub;
	scanf("%d", &n);
	vector<int> exam(n);
	for (auto &e : exam)
		scanf("%d", &e);
	scanf("%d %d", &total, &sub);
	long long need_person = 0;

	for (auto student : exam) {
		int remain_student = student - total;
		need_person++;
		if (remain_student <= 0)
			continue;

		need_person += (remain_student / sub);
		if (remain_student % sub != 0)
			need_person++;
		}
	printf("%lld\n", need_person);
	return 0;
}