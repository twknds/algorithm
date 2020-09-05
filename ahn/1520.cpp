#include <stdio.h>
int map[510][510];
int dp[510][510];
int m, n;
int f(int y, int x) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	if (x == 0 && y == 0)return 1;
	if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[ny][nx] > map[y][x] && 0 <= nx && nx < n && 0 <= ny && ny < m) {
				dp[y][x] += f(ny, nx);
			}
		}
	}
	return dp[y][x];
}
int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}
	printf("%d", f(m - 1, n - 1));
	return 0;
}
