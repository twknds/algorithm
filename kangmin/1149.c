#include <stdio.h>


int min(int a, int b)
{
	return a < b ? a : b;
}

int main() {

	int i;
	int N;
	int dp[3];
	int dp2[3];
	int arr[3];
	int mini;

	dp[0] = dp[1] = dp[2] = 0;


	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		dp2[0] = dp[0];
		dp2[1] = dp[1];
		dp2[2] = dp[2];

		dp[0] = min(dp2[1], dp2[2]) + arr[0];
		dp[1] = min(dp2[0], dp2[2]) + arr[1];
		dp[2] = min(dp2[0], dp2[1]) + arr[2];
	}

	mini = min(min(dp[0], dp[1]), dp[2]);
	printf("%d", mini);

}