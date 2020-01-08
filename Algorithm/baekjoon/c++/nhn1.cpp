#include<iostream>

using namespace std;

int a[100];
int main() {
	for (int i = 0; i < 100; i++)
		a[i] = i;

	int *p = a + 100;
	cout << p[-30] << endl;

}