#include <stdio.h>
#include <string.h>

void quicksort(int left, int right, int *ary);

int main()
{
	int i;
	int * delay_time;
	char * input; char * ptr;
	int * ary;
	int size;
	int sum = 0;
	scanf("%d ", &size);

	ary = (int*)malloc(sizeof(int) * size);
	delay_time = (int*)malloc(sizeof(int) * size);
	input = (char*)malloc(sizeof(char) * (5 * (size+1)));

	gets(input);
	i = 0;
	ptr = strtok(input, " ");
	while (ptr != NULL)
	{
		ary[i++] = atoi(ptr);
		ptr = strtok(NULL, " ");
	}
	
	quicksort(0, size - 1, ary);

	for (i = 0; i < size; i++)
		delay_time[i] = 0;

	for (i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++)
			delay_time[i] += ary[j];
		sum += delay_time[i];
	}
	printf("%d", sum);
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