#include<stdio.h>
#include<math.h>
int col[1000][3];
int cost[1000][3];
int main(void) {
	int n;
	int min = 1000000;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	for (int i = 1; i <= n; i++) {
		if (col[i - 1][1] <= col[i - 1][2])col[i][0] = col[i - 1][1] + cost[i][0];
		else col[i][0] = col[i - 1][2] + cost[i][0];
		if (col[i - 1][0] <= col[i - 1][2])col[i][1] = col[i - 1][0] + cost[i][1];
		else col[i][1] = col[i - 1][2] + cost[i][1];
		if (col[i - 1][0] <= col[i - 1][1])col[i][2] = col[i - 1][0] + cost[i][2];
		else col[i][2] = col[i - 1][1] + cost[i][2];
	}
	for (int i = 0; i < 3; i++) {
		if (min > col[n][i])min = col[n][i];
	}
	printf("%d", min);
	return 0;
}