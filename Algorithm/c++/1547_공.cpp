#include<cstdio>

int cup[4];
bool check[4];
int main() {
	int k;
	scanf("%d", &k);
	cup[1] = 1;
	cup[2] = 2;
	cup[3] = 3;
	while (k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		check[x] = true;
		check[y] = true;
		if (check[1] && check[2]) {
			int temp = cup[1];
			cup[1] = cup[2];
			cup[2] = temp;
		}
		else if (check[1] && check[3]) {
			int temp = cup[1];
			cup[1] = cup[3];
			cup[3] = temp;
		}
		else {
			int temp = cup[2];
			cup[2] = cup[3];
			cup[3] = temp;
		}
		check[x] = false;
		check[y] = false;
	}
	for (int i = 1; i < 4; i++){
		if (cup[i] == 1)
			printf("%d\n", i);
	}
	return 0;
}