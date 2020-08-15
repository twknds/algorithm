#include<stdio.h>
#include<string.h>
char c[51][51];
int main(void) {
	FILE* fin;
	int m, n;
	int max = 0;
	int cnt = 0, cnt2 = 0;
	int k;	
	fin = fopen("input.txt", "r");
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", c[i]);
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		cnt = 0;
		cnt2 = 0;
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '0')cnt++;
		}
		if (cnt <= k && (cnt % 2) == (k % 2)) {
			for (int j = 0; j < n; j++) {
				if (strcmp(c[i], c[j]) == 0)cnt2++;
			}
		}
		if (max < cnt2)max = cnt2;
	}
	printf("%d\n", max);
}