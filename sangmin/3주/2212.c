#include <stdio.h>
#include <string.h>

void quicksort(int left, int right, int *ary);

int main()
{
	int sensor;
	int k, i;
	int sum = 0;
	int * ary; int * distance;

	scanf("%d", &sensor);
	scanf("%d ", &k);

	distance = (int*)malloc(sizeof(int) * (sensor-1));
	ary = (int*)malloc(sizeof(int) * sensor);
	for (i = 0; i < sensor; i++)
		scanf("%d", &ary[i]);
	quicksort(0, sensor-1, ary);

	for (i = 0; i < sensor - 1; i++)
		distance[i] = ary[i + 1] - ary[i];

	quicksort(0, sensor - 2, distance);

	for (i = 0; i < sensor - k; i++)
		sum += distance[i];

	printf("%d\n", sum);
	return 0;
}

void quicksort(int left, int right, int * ary)
{
	if (left >= right)
		return;
	int temp, pivot = ary[left];
	int i = left + 1, j = right;
	while (i <= j)
	{
		while (i <= right && ary[i] <= pivot)
			i++;
		while (j > left && ary[j] >= pivot)
			j--;

		if (i > j)
		{
			temp = ary[j];
			ary[j] = pivot;
			ary[left] = temp;
		}
		else
		{
			temp = ary[j];
			ary[j] = ary[i];
			ary[i] = temp;
		}
	}
	quicksort(left, j - 1, ary);
	quicksort(j + 1, right, ary);
}