#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[501][501];
int dp[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int M, N;

int main()
{	
	scanf("%d %d", &M, &N);

	for (int i = 0; i <= M; i++)
		for (int j = 0; j <= N; j++) {
			map[i][j] = 20000;
			dp[i][j] = -1;
		}

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	printf("%d", dfs(1, 1));
}

int dfs(int x, int y)
{
	if (x == N && y == M)
		return 1;
	
	if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++)
		{
			int n_x = x + dx[i];
			int n_y = y + dy[i];

			if(n_y > 0 && n_y <= M && n_x > 0  && n_x <= N && map[y][x] > map[n_y][n_x])
				dp[y][x] += dfs(n_x, n_y);
		}
	}
	return dp[y][x];
}