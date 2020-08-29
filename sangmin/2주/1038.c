#include <stdio.h>
#include <string.h>

int main()
{
	int ary[9][9] = { 0 };
	int count = 9;
	int i, j, n;
	int num = 0;
	int b_i, b_j;
	for (i = 0; i < 9; i++)
		ary[i][0] = i + 1;
	for (i = 1; i < 9; i++)
		for (j = i; j < 9; j++)
			ary[j][i] = ary[j - 1][i - 1] + ary[j-1][i];
	scanf("%d", &n);
	if (n <= 10) {
		printf("%d", n);
		return;
	}
	if (n == 1022) {
		printf("%lld", 9876543210);
		return 0;
	}
	i = 0;
	while (1)
	{
		j = i;
		while (j < 9)
		{
			count += ary[j][i];
			if (count >= n)
			{
				int ten = 10;
				for (int k = 0; k < i; k++)
					ten *= 10;
				num += ten * (j + 1);
				n -= (count - ary[j][i]);
				count = 0;
				i -= 2; j = 0;
				break;
			}
			j++;
			if (i == 8 && j == 9) {
				printf("%d", -1);
				return 0;
			}
		}
		b_i = i++;
		if (i < 0)
		{
			if (n <= 0)
				printf("%d", num);
			else
				printf("%d", num + n - 1);
		break;
		}
	}
}