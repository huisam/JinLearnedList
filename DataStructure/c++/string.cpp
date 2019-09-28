#include<iostream>

using namespace std;

void mstrcpy(char *dst, char *src) {
	int i = 0;
	while (dst[i] = src[i++]);
}

int mstrcmp(char *str1, char *str2) {
	int pos = 0;
	while (str1[pos]) {
		if (str1[pos] != str2[pos]) {
			break;
		}
		pos++;
	}
	return str1[pos] - str2[pos];
}

int mstrlen(char *str1) {
	int len = 0;
	while (str1[++len]);
	return len;
}


int main() {
	char abc[4] = { 'b', 'c' };
	char b[5] = "abc";

	cout << mstrcmp(abc, b) << '\n';
	mstrcpy(abc, b);
	cout << abc[0] << '\n' << mstrlen(abc);
	return 0;
}