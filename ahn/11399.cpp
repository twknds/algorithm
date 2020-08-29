#include<stdio.h>
#include<string.h>
int num[1001];
void sort(int s, int e) {
	if (s >= e)return;
	int pivot = num[(s + e) / 2];
	int temp;
	int l = s;
	int r = e;
	while (l <= r) {
		while (num[l] < pivot)l++;
		while (num[r] > pivot)r--;
		if (l <= r) {
			temp = num[l];
			num[l] = num[r];
			num[r] = temp;
			l++; r--;
		}
	}
	sort(s, r);
	sort(l, e);
}
int main(void) {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cnt += num[j];
		}
	}
	printf("%d", cnt);
}