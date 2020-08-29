#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len[10];
int max;
int num[10];
int alp[26];
void sort() {
	int temp;
	for (int i = 0; i < 26; i++) {
		for (int j = i; j < 26; j++) {
			if (alp[i] < alp[j]) {
				temp = alp[i];
				alp[i] = alp[j];
				alp[j] = temp;
			}
		}
	}
}
int main(void) {
	int cnt = 9;
	char ch = 'A';
	int num2 = 1;
	int sum = 0;
	int n;
	char name[10][100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", name[i]);
		len[i] = strlen(name[i]);
		if (len[i] > max) {
			max = len[i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len[i]; j++) {
			num2 = 1;
			for (int k = 0; k < len[i] - j - 1; k++)num2 *= 10;
			alp[name[i][j] - 'A'] += num2;
		}
	}
	sort();
	for (int i = 0; i < 10; i++) {
		if (alp[i] == 0)break;
		alp[i] *= cnt;
		cnt--;

	}
	for (int i = 0; i < 10; i++) {
		if (alp[i] != 0)sum += alp[i];
	}
	printf("%d", sum);
}