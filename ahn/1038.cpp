#include<stdio.h>
#include<string.h>
int num[11][11];
int main(void) {
	FILE* fin;
	int m;
	int i;
	int su = -1;
	int err = 0;
	int cnt = 0;
	fin = fopen("input.txt", "r");
	//fscanf(fin,"%d", &m);
	scanf("%d", &m);
	if (m >= 1023) {
		printf("-1\n");
		return 0;
	}
	num[0][0] = 0;
	for (int i = 1; i < 10; i++)num[0][i] = 1;
	while (err == 0) {
		su++;
		for (i = 0 + su; i < 10; i++) {
			if (su != 0) {
				if (su == 1)num[0][0] = 1;
				for (int j = 0; j < i; j++)num[su][i] += num[su - 1][j];
			}
			cnt += num[su][i];
			if (cnt >= m) {
				err = 1;
				break;
			}
		}
	}
	int k;
	int temp;
	temp = cnt;
	temp -= num[su][i];
	printf("%d", i);
	for (int j = su - 1; j >= 0; j--) {
		for (k = 0; k < i; k++) {
			temp += num[j][k];
			if (temp >= m) {
				printf("%d", k);
				i = k;
				temp -= num[j][k];
				break;
			}
		}
	}
}