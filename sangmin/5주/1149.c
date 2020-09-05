#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

ary[1000][3];
int num;
void value(int start, int N);

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &ary[i][j]);
	for(int i = 0; i<3; i++)
	value(i, N);
	printf("%d", num);
}

int set_min(int * min_ary, int i)
{
	int min, j = 0;
	if (j != i)
		min = min_ary[j];
	else
		min = min_ary[j + 1];

	for (j = 0; j < 3; j++)
	{
		if (j == i)
			continue;
		else
			if (min_ary[j] < min)
				min = min_ary[j];
	}
	return min;
}

void value(int start, int N)
{
	int min_ary[3];
	int copy_ary[3];
	int n = 3;
	for (int i = 0; i < 3; i++)
	{
		if (i == start)
			min_ary[i] = 99999;
		else
		min_ary[i] = ary[0][start] + ary[1][i];
	}
	while (n <= N)
	{
		for (int i = 0; i < 3; i++)
			copy_ary[i] = set_min(min_ary, i) + ary[n - 1][i];

		for (int i = 0; i < 3; i++)
			min_ary[i] = copy_ary[i];
		n++;
	}
	if (start == 0)
		num = set_min(min_ary, 4);
	else if (num > set_min(min_ary, 4))
		num = set_min(min_ary, 4);
}