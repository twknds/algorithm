#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int queue[10002];
int node[1002][10002];
int end[1002];
int mem[1002];
int front, rear;
int a, b, c, d, e;
int cnt;
void bfs(int start) {
	int err = 0;
	if (front > rear)return;
	printf("%d ", start);
	mem[cnt++] = start;
	if (cnt == a)return;
	for (int i = 0; i < end[start]; i++) {
		err = 0;
		for (int j = 0; j < rear; j++) {
			if (node[start][i] == queue[j] || node[start][i] == c) {
				err = 1;
				break;
			}
		}
		if (err == 0)queue[rear++] = node[start][i];
	}
	bfs(queue[front++]);
}
void dfs(int start) {
	int err = 0;
	printf("%d ", start);
	mem[cnt++] = start;
	if (cnt == a)return;
	for (int i = 0; i < end[start]; i++) {
		err = 0;
		if (node[start][i] == 0)return;
		for (int j = 0; j < cnt; j++) {
			if (node[start][i] == mem[j]) {
				err = 1;
				break;
			}
		}
		if (err == 0)dfs(node[start][i]);
	}
}
void sort(int i, int s, int e) {
	if (s >= e)return;
	int pivot = node[i][(s + e) / 2];
	int temp;
	int l = s;
	int r = e;
	while (l <= r) {
		while (node[i][l] < pivot)l++;
		while (node[i][r] > pivot)r--;
		if (l <= r) {
			temp = node[i][l];
			node[i][l] = node[i][r];
			node[i][r] = temp;
			l++; r--;
		}
	}
	sort(i, s, r);
	sort(i, l, e);
}
int main(void) {
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 0; i < b; i++) {
		scanf("%d%d", &d, &e);
		node[d][end[d]++] = e;
		node[e][end[e]++] = d;
	}
	for (int i = 1; i <= a; i++) {
		sort(i, 0, end[i] - 1);
	}
	dfs(c);
	printf("\n");
	rear = 0;
	cnt = 0;
	bfs(c);
}